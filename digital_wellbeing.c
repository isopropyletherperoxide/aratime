#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int minutes_to_seconds(int input);

void kill_process(char *);

int main(int argc, char *argv[]) {
        if (argc < 3) {
                printf("Not enough arguments!\n\nUsage: digital_wellbeing time(in minutes) proc_name1 proc_name2 proc_name_n\n\nExample: digital_wellbeing 30 Discord firefox\n");
                exit(1);
        }
  int sleep_minutes = atoi(argv[1]);
  sleep(minutes_to_seconds(sleep_minutes));
  while (1) {
    for (int i = 2; i < argc; i++) {
      kill_process(argv[i]);
    }
    sleep(10);
  }
  return 0;
}

void kill_process(char *process) {
  FILE *cmd;
  char command[1024];

  strcpy(command, "pgrep ");
  strcat(command, process);
  cmd = popen(command, "r");
  char result[1024];
  while (fgets(result, sizeof(result), cmd)) {
    printf("%s", result);
    //    sleep(minutes_to_seconds(1));
    kill(atoi(result), SIGTERM);
  }
  int exit_code = pclose(cmd) / 256;

  if (exit_code == 0) {
    printf("Ended successfully!\n");
  } else {
    printf("Killing process %s failed with exit code %i\n", process, exit_code);
  }
}

int minutes_to_seconds(int input) { return input * 60; }

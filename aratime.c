#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int minutes_to_seconds(int input);
void kill_process(char *);
void countdown_timer(int);
char *minutes_to_str(int);

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Not enough arguments!\n\nUsage: nohup aratime time(in "
           "minutes) proc_name1 proc_name2 proc_name_n\n\nExample: nohup "
           "aratime 30 Discord firefox\n");
    exit(1);
  }
  int sleep_minutes = atoi(argv[1]);
  if (sleep_minutes != 0 ){
  countdown_timer(minutes_to_seconds(sleep_minutes));
  }
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

void countdown_timer(int seconds) {
  for (int i = seconds - 1; i >= 0; i--) {
    fputs("\b\b\b\b\b\b", stdout);
    printf("%i:%02d", i / 60, (i - i / 60));
    fflush(stdout);
    sleep(1);
  }
 fputs("\n", stdout);
}

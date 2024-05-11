#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>

int init_module(void) {
  printk(KERN_INFO "Hello world!\n}");
  struct task_struct *t = NULL;

  for_each_process(t) {
    printk("Task %s (pid = %d)\n", t->comm, task_pid_nr(t));
    if ((strcmp(t->comm, "aratime") == 0)) {

      /* if matched that is your user process PID */
      printk("Set process %s to unkillable", t->comm);
      t->signal->flags |= SIGNAL_UNKILLABLE;
    }
  }
  return 0;
}

void cleanup_module(void) { printk(KERN_INFO "Goodbye World\n"); }

MODULE_LICENSE("GPL");

#include <linux/module.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/sysinfo.h>
#include <linux/seq_file.h>
#include <linux/slab.h>
#include <linux/mm.h>
#include <linux/swap.h>
#include <linux/timekeeping.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yásmin Monterroso");
MODULE_DESCRIPTION("ram_grupo18");
MODULE_VERSION("0.01");

static int escribir_a_proc(struct seq_file *file_proc, void *v) {       

    seq_printf(file_proc,"{\"Total_RAM\":\"\",\n\"Uso_RAM\":\"\",\n\"Porcentaje\":\"\",\n\"Libre_RAM\":\"\",\n }");
 
    return 0;
}

static int abrir_aproc(struct inode *inode, struct  file *file) {
  return single_open(file, escribir_a_proc, NULL);
}

static struct proc_ops archivo_operaciones = {    
    .proc_open = abrir_aproc,
    .proc_read = seq_read
};

static int __init escribir_archivo(void) {
    proc_create("timestamps", 0, NULL, &archivo_operaciones);
    printk(KERN_INFO "Archivo creado\n");
    return 0;
}

/* Llamada a las cosas */

module_init(escribir_archivo);
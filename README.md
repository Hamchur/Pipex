# Pipex
Цель этого проекта - немного глубже понять, как работают каналы и перенаправления.

Эта программа берет входной файл, выходной файл для перенаправления команд STDIN (<), STDOUT (>) и 2 в конвейер.
Pipe — это команда в Linux, которая позволяет вам использовать две или более команд, так что вывод одной команды служит вводом для следующей. 

Короче говоря, вывод каждого процесса непосредственно в качестве ввода для следующего, как конвейер. Символ «|» обозначает трубу.

Конвейеры помогают вам смешивать две или более команд одновременно и запускать их последовательно. 
Вы можете использовать мощные команды, которые могут выполнять сложные задачи в один миг.

Давайте разберемся в этом на примере.

Когда вы используете команду «cat» для просмотра файла, который занимает несколько страниц, подсказка быстро переходит к последней странице файла, и вы не видите содержимое в середине.

Выполните следующую команду в оболочке:
```
$> <file1 cmd1 | cmd2> файл2
```
Задача этого проекта - создать программу pipex, которая заставит ее работать так:

```
$> ./pipex file1 cmd1 cmd2 file2
```

Для запуска нажмите

```
make

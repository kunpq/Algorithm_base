/*测试文件*/
#include "../include/queue.h"
int main(void) {
  Queue *line; //定义队列
  Item temp;
  int max = 100;
  char ch;
  InitializeQueue(max, line);
  puts("Testing the Queue interface. Type a to add a value,");
  puts("type d to delete a value, and type q to quit.");
  while ((ch = getchar()) != 'q') {
    if (ch != 'a' && ch != 'd') //忽略其他输出
      continue;
    if (ch == 'a') {
      GetInfo(&temp);
      EnQueue(temp, line);
    } else {
      DeQueue(&temp, line);
    }
  }
  printf("\n%d items in queue\n", line->items);
  puts("Type a to add, d to delete, q to quit:");

DisposeQueue(line);
puts("Bye!");

return 0;
}
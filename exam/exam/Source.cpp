 #include <iostream>
 using namespace std;
 class cup
{
  public:
   cup(char newColor, int newHeight);
   cup(char newColor);
   cup();
   char getC();
   int getH();
  private:
   char color;
   int height;
 };

 int main()
 {
  cup glass('C'), mug;

  cout << "The cups at point 1 are glass:" << glass.getC() << glass.getH() << " mug:" << mug.getC() << mug.getH() << endl;
  glass = cup('O',3);
  cout << "The cups at point 2 are glass:" << glass.getC() << glass.getH() << " mug:" << mug.getC() << mug.getH() << endl;
  mug = cup('B');
  cout << "The cups at point 3 are glass:" << glass.getC() << glass.getH() << " mug:" << mug.getC() << mug.getH() << endl; 
  mug = cup('G',6);
  cout << "The cups at point 4 are glass:" << glass.getC() << glass.getH() << " mug:" << mug.getC() << mug.getH() << endl;

  system("Pause");
  return 0;
}

cup::cup(char newColor, int newHeight)
{
  color = newColor;
  height = newHeight;
 }

 cup::cup(char newColor)
 {
  color = newColor;
  height = 2;
 }

 cup::cup()
 {
  color = 'Q';
  height = 1;
 }

 char cup::getC()
 {
  return color;
 }

 int cup::getH()
 {
  return height;
 }

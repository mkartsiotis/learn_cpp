class Chessboard {
public:
  Chessboard();
  ~Chessboard();
  void set_pawn_to_pos(char y, char x);
  void print();
private:
  char box[8][8];
  bool is_visible;
};

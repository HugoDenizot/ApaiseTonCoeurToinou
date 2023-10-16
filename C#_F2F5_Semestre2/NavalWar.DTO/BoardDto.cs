namespace NavalWar.DTO
{
    public class BoardDto
    {
        public int Id { get; set; }
        public int[,] cellules { get; set; }

        public BoardDto() {
            cellules = new int[10, 10];
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    cellules[i, j] = 0;
                }
            }
        }

    }
}
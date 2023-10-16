using NavalWar.DTO;
using System.ComponentModel.DataAnnotations;

namespace NavalWar.DAL.Models
{
    public class Board
    {
        [Key]
        public int Id { get; set; }
        public string cellules { get; set; }

        //public int[,] cellules { get; set; }

    }
}

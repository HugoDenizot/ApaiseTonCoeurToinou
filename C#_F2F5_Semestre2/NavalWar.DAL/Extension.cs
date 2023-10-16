using NavalWar.DAL.Models;
using NavalWar.DTO;
using NavalWar.DTO.WebDTO;
using System.Text.Json;

namespace NavalWar.DAL
{
    public static class Extension
    {
        public static PlayerDTO toDTO(this Player j){
            return new PlayerDTO() { _id = j._id,
                _name = j._name,
                SessionId = j.PlayerSessionId,
                _shotBoard = j._shotBoard,
                _personalBoard= j._personalBoard,

            };
        }
        public static Player toEntity(this PlayerDTO j)
        {
            return new Player()
            {
                _id = j._id,
                _name = j._name,
                PlayerSessionId = j.SessionId,
                _shotBoard = j._shotBoard,
                _personalBoard = j._personalBoard,

            };
        }

        public static SessionDTO toDTO(this Session s)
        {
            return new SessionDTO()
            {
                ID = s.ID,
                NameJoueurEnCours=s.NameJoueurEnCours,
    };
        }

        public static Session toEntity(this SessionDTO s)
        {
            return new Session()
            {
                ID = s.ID,
                NameJoueurEnCours = s.NameJoueurEnCours,
            };
        }

        public static Board toEntity(this BoardDto b)
        {
            int[,] matrix = b.cellules;

            List<int> list = new List<int>();
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    list.Add(matrix[i, j]);
                }
            }

            JsonSerializerOptions options = new JsonSerializerOptions
            {
                WriteIndented = true // pour indenter le JSON généré
            };

            string json = JsonSerializer.Serialize(list, options);

            return new Board()
            {
                Id = b.Id,
                cellules = json,
            };
        }

        public static BoardDto toDto(this Board b)
        {
            List<int> list = JsonSerializer.Deserialize<List<int>>(b.cellules);

            int[,] matrix = new int[10, 10];
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    matrix[i, j] = list[i * matrix.GetLength(1) + j];
                }
            }

            return new BoardDto()
            {
                Id = b.Id,
                cellules = matrix
            };
        }


    }
}

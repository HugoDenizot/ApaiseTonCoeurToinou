using Microsoft.AspNetCore.Mvc;
using NavalWar.DTO;
using NavalWar.DTO.WebDTO;
using NavalWar.Business;
using NavalWar.DAL.Models;
using NavalWar.DAL;
using System.Collections.Generic;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Cors;
using Newtonsoft.Json.Linq;
using Newtonsoft.Json;
// For more information on enabling Web API for empty projects, visit https://go.microsoft.com/fwlink/?LinkID=397860

namespace NavalWar.API.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class GameAreaController : ControllerBase
    {

        private readonly IGameService _gameService;

        public GameAreaController(IGameService gameService)
        {
            _gameService = gameService;
        }


        // POST api/<GameAreaController>
        [HttpGet("Get Player")]
        public PlayerDTO GetPlayer(int id)
        {
            return _gameService.GetPlayer(id);

        }

        [HttpGet("GetSession/{id}")]
        public IActionResult GetSession(int id)
        {
            return Ok(_gameService.GetSession(id));
        }

        [HttpGet("GetPersonnalBoard")]
        public IActionResult GetPersonalBoard(int id)
        {
            int[,] matrix = _gameService.getPersonalBoard(id);
            List<List<int>> listOfLists = new List<List<int>>();
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                List<int> row = new List<int>();
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    row.Add(matrix[i, j]);
                }
                listOfLists.Add(row);
            }
            //Response.ContentType = "application/json";
            return Ok(listOfLists);
        }

        [HttpGet("GetShotBoard")]
        public List<List<int>> GetShotBoard(int id)
        {
            int[,] matrix = _gameService.getShotBoard(id);
            List<List<int>> listOfLists = new List<List<int>>();
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                List<int> row = new List<int>();
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    row.Add(matrix[i, j]);
                }
                listOfLists.Add(row);
            }
            return listOfLists;
        }


        [HttpGet("CreateGame")]
        public IActionResult CreatePlayer()
        {
            string nomJoueur = "Joueur1";
            try
            {
                PlayerDTO playerResponseDto = _gameService.CreatePlayer(nomJoueur);

                return Ok(playerResponseDto);
            }
            catch (Exception ex)
            {
                return StatusCode(StatusCodes.Status500InternalServerError, ex.Message);
            }
        }

        [HttpPost]
        [Route("api/sessions/players/{playerId}/placeship")]
        public IActionResult PlaceShip(int playerId, [FromBody] PlaceDTO p)
            //int taille, int h, int posX, int posY )
        {
            _gameService.PlaceShips(p.taille, p.h, p.PosX, p.PosY, playerId);

            return Ok();
        }


        [HttpPost]
        [Route("api/players/{playerId}/shot")]
        public IActionResult Shot(int playerId, [FromBody] ShotDto shot)
        {
            TireDto t = new TireDto(int.Parse(shot.PosX),int.Parse(shot.PosY));
            return Ok(_gameService.ShotOn(t, playerId));
        }

        [HttpGet("RejoindrePartie/{id_partie}")]
        public IActionResult RejoindreGame(int id_partie)
        {   
            string name = "Joueur2";
            return Ok(_gameService.rejoindrePartie(id_partie, name));
        }

        // PUT api/<GameAreaController>/5
        [HttpPut("update Player")]
        public void Put(int id, string value)
        {
            _gameService.UpdatePlayer(id,value);
        }

        // DELETE api/<GameAreaController>/5
        [HttpDelete("Delete player")]
        public void Delete(int id)
        {
            _gameService.DeletePlayer(id);
        }


    }
}

   
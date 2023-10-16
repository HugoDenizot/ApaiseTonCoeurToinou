import { Component } from '@angular/core';
import { AfterViewInit } from '@angular/core';
import { HttpClient, HttpParams,HttpHeaders } from '@angular/common/http';
import { Observable } from 'rxjs';
import {Router } from '@angular/router';

@Component({
  selector: 'app-creation-partie',
  templateUrl: './creation-partie.component.html',
  styleUrls: ['./creation-partie.component.css']
})
export class CreationPartieComponent {
  constructor(private http: HttpClient,private router : Router) { }

  Id:number=0;

  ngAfterViewInit() {
    localStorage.setItem("taillesSav",JSON.stringify([5,4,3,3,2]));
    let apiUrl = 'https://localhost:7080/api/GameArea/CreateGame';
    this.http.get<any>(apiUrl).subscribe(joueur => {
      this.Id=joueur.sessionId;
      this.router.navigate(['placement'],{ queryParams: { id_player: joueur._id,id_session:joueur.sessionId,nom:joueur._name } });
    });
  }

  goHome(): void {
    //this.router.navigate(['/profile']);
  }

  createJoueur(nomJoueur: string){
    
  }

  createNewJoueur() {
    this.createJoueur('Hugo')
      
  }

  

}

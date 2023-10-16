import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';


import { CreationPartieComponent } from 'src/creation-partie/creation-partie.component';
import { RejoindrePartieComponent } from 'src/rejoindre-partie/rejoindre-partie.component';
import { AccueilComponent } from 'src/accueil/accueil.component';

import { GameComponent } from 'src/game/game.component';
import { PlacementComponent } from 'src/placement/placement.component';

const routes: Routes = [
  {path: '',component: AccueilComponent},
  { path: 'rejoindre_partie', component: RejoindrePartieComponent },
  { path: 'creation_partie', component: CreationPartieComponent }, 
  { path: 'game', component: GameComponent },
  { path: 'placement', component: PlacementComponent },
];

@NgModule({
  declarations:[
    PlacementComponent,
    AccueilComponent,
    GameComponent,
    CreationPartieComponent,
    RejoindrePartieComponent
  ],

  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }

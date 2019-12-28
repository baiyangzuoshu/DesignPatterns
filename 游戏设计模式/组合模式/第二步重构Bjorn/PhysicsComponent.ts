
import  {GameObject} from './GameObject'

class   Volume{}
export class   World{
    resolveCollision(volume:Volume,x:number,y:number,velocity:number):void{}
}

export interface   PhysicsComponent{
    update(bjorn:GameObject,world:World):void;
}

export  class PlayerPhysicsComponent implements  PhysicsComponent{
    volume:Volume=new Volume;
    update(bjorn:GameObject,world:World){
        bjorn.x+=bjorn.velocity;
        world.resolveCollision(this.volume,bjorn.x,bjorn.y,bjorn.velocity);
    }
}
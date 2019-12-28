
import  {Bjorn} from './Bjorn'

class   Volume{}
class   World{
    resolveCollision(volume:Volume,x:number,y:number,velocity:number):void{}
}

export  class   PhysicsComponent{
    volume:Volume=new Volume;
    update(bjorn:Bjorn,world:World){
        bjorn.x+=bjorn.velocity;
        world.resolveCollision(this.volume,bjorn.x,bjorn.y,bjorn.velocity);
    }
}
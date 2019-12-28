
import  {GameObject} from './GameObject';
class   Controller{
    static getJoystickDirection():number
    {
        return 0;
    }
}
const   DIR_LEFT:number=0;
const   DIR_RIGHT:number=1;

export interface   InputConponent{
    update(bjorn:GameObject):void;
}

export  class PlayerInputConponent  implements  InputConponent{

    static  WALK_ACCELERATION:number=1;

    update(bjorn:GameObject){
        switch(Controller.getJoystickDirection()){
            case    DIR_LEFT:
                bjorn.velocity-=PlayerInputConponent.WALK_ACCELERATION;
                break;
            case    DIR_RIGHT:
                bjorn.velocity+=PlayerInputConponent.WALK_ACCELERATION;
                break;
        }
    }
}
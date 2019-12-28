
import  {Bjorn} from './Bjorn';
class   Controller{
    static getJoystickDirection():number
    {
        return 0;
    }
}
const   DIR_LEFT:number=0;
const   DIR_RIGHT:number=1;

export  class   InputConponent{

    static  WALK_ACCELERATION:number=1;

    update(bjorn:Bjorn){
        switch(Controller.getJoystickDirection()){
            case    DIR_LEFT:
                bjorn.velocity-=InputConponent.WALK_ACCELERATION;
                break;
            case    DIR_RIGHT:
                bjorn.velocity+=InputConponent.WALK_ACCELERATION;
                break;
        }
    }
}
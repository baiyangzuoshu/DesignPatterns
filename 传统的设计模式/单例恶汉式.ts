export  class   HungerSingleton{
    
    private static  _instance:HungerSingleton=new HungerSingleton();
    private constructor(){

    }

    static  getInstance():HungerSingleton{
        return this._instance;
    }
}
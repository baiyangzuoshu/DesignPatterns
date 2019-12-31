export  class   Singleton{
    static  _instance:any=null;
    private constructor(){}

    static  getInstance():Singleton{
        if(this._instance==null){
            this._instance=new Singleton();
        }
        return this._instance;
    }

    static  freeInstance():void{
        if(this._instance){
            this._instance=null;
        }
    }
}
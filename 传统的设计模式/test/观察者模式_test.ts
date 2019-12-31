import { PlayserObserver, Secretary } from "../观察者模式";

let p1=new PlayserObserver;
let p2=new PlayserObserver;
let p3=new PlayserObserver;

let secretary=new Secretary;
secretary.addPlayerObserver(p1);
secretary.addPlayerObserver(p2);
secretary.addPlayerObserver(p3);

secretary.Notify('下雨了');
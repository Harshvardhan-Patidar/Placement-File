const express=require("express");
const app=express();
app.use(express.json());

const port=8081;
const item=["apple","banana","orange"];

app.get("/list",(req,res)=>{
    res.status(200);
    res.send(item);
})

app.post("/list",(req,res)=>{
    item=req.body.name;
    res.status(200).send("item added");
})

app.delete("/list",(req,res)=>{
    let deletedItem=req.body.name;
    item.find((element,index)=>{
        if(element==deletedItem){
            item.splice(index,1);
        }
    })
    res.status(200).send("item deleted");
})

app.listen(port,()=>{
    console.log("Server running on Port:",port);
});
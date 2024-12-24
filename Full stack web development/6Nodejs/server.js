const http=require('http');
const port=8081;

const toDolist=['learn','puja karo','earn','gym','eat','sleep'];

http.createServer((req,res)=>{
    const {method,url}=req;
    if(url=='/todo'){
        if(method=='GET'){
            res.writeHead(200,{"Content-Type":"text/html"});
            res.write(toDolist);
        }
        else if(method=='POST'){
            var body='';
            req.on("error",(e)=>{
                console.log(e);
            })
            .on("data",(data)=>{
                body+=data;
            })
            .on("end",()=>{
                body=JSON.parse(body);
                console.log(body);

                toDolist.push(body.item);
            })
        }
        else{
            res.writeHead(501);
        }
    }
    else{
        res.writeHead(404);
    }

    res.end();
})
.listen(port,()=>{
    console.log("Server running on Port:",port);
})
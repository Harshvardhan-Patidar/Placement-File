import {React,useState} from "react";

const State=()=>{
    const [count,setCount]=useState(0);
    const decreament=()=>{
        setCount(count-1)
    }
    return(
        <>
        <h2>{count}</h2>
        <button onClick={()=>setCount(count+1)}>Click to Increament</button>
        <button onClick={()=>decreament()}>Click to Decrement</button>
        </>
    )
}

export default State;
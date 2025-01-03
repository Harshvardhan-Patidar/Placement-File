import React, { Component } from "react";

const BaseHoc=(Component)=>(...props)=>{
    return(
        <>
        <h1>This is our navbar</h1>
        <Component {...props} />
        <h2>This is our footer</h2>
        </>
    )
}

export default BaseHoc
import React from "react";
import BaseHoc from "../../highOrderComponent/baseHoc";

class ClassComponent extends React.Component {
    render(){
        return(
            <div>
                <h1>Class Component Example</h1>
            </div>
        )
    }
}

export default BaseHoc(ClassComponent)
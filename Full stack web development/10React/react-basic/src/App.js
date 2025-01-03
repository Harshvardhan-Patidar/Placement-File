import "./App.css";
import { Routes,Route } from "react-router-dom";
import ClassComponent from "./components/pages/ClassComponent.jsx";
import FuntionComponent from "./components/pages/funtionComponent.jsx";
import State from "./components/state.jsx";
import Props from "./components/props.jsx";
import BaseHoc from "./highOrderComponent/baseHoc.jsx";

function App() {
  let naam="hp"
  return (
    <div className="App">
      <header className="App-header">
        <h1>Types of Components in React</h1>
        <h3>Go to "/class" "/funtion"</h3>
      </header>

      <Routes>
        <Route path='/class' element={<BaseHoc><ClassComponent/></BaseHoc>} />
        <Route path="/funtion" element={<FuntionComponent/>} /> 
      </Routes>
      
      <State />
      <Props name="Harsh" age={20} naam={naam} />
    </div>
  );
}

export default App;
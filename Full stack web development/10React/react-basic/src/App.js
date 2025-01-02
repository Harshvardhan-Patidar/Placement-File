import "./App.css";
import ClassComponent from "./components/ClassComponent.jsx";
import FuntionComponent from "./components/funtionComponent.jsx";
import State from "./components/state.jsx";
import Props from "./components/props.jsx";

function App() {
  let naam="hp"
  return (
    <div className="App">
      <header className="App-header">
        <h1>Types of Components in React</h1>
      </header>
      <ClassComponent />
      <FuntionComponent />
      <State />
      <Props name="Harsh" age={20} naam={naam} />
    </div>
  );
}

export default App;

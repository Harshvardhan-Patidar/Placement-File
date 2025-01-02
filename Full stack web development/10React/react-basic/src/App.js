import './App.css';
import ClassComponent from "./components/ClassComponent.jsx"
import FuntionComponent from "./components/funtionComponent.jsx"

function App() {
  return (
    <div className="App">
      <header className="App-header">
        <h1>Types of Components in React</h1>
      </header>
      <ClassComponent/>
      <FuntionComponent/>
    </div>
  );
}

export default App;

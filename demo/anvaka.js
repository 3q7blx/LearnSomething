let path = require('ngraph.path');

let createGraph = require('ngraph.graph');
let graph = createGraph();

// Our graph has cities:
graph.addNode('NYC', {x: 0, y: 0});
graph.addNode('Boston', {x: 1, y: 1});
graph.addNode('Philadelphia', {x: -1, y: -1});
graph.addNode('Washington', {x: -2, y: -2});

// and railroads:
graph.addLink('NYC', 'Boston');
graph.addLink('NYC', 'Philadelphia');
graph.addLink('Philadelphia', 'Washington');


console.log(graph)

let pathFinder = path.aStar(graph); // graph is https://github.com/anvaka/ngraph.graph

// now we can find a path between two nodes:
let fromNodeId = "NYC";
let toNodeId = "Philadelphia";
let foundPath = pathFinder.find(fromNodeId, toNodeId);
console.log(foundPath)
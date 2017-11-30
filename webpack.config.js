const path = require('path')

module.exports = {
  entry: './src/Main.bs.js',
  output: {
    path: path.resolve(__dirname, 'public'),
    filename: 'main.js'
  },
  resolve: {
    // Add .re and .ml to the list of extensions webpack recognizes
    extensions: ['.re', '.ml', '.js']
  }
}

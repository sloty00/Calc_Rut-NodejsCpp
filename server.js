const express = require('express');
const addon = require('./build/Release/rut_calculator');
const app = express();
const port = 3000;

app.use(express.json());

app.post('/calculate', (req, res) => {
    const { rut } = req.body;
    if (typeof rut === 'number') {
        const result = addon.calculateDV(rut);
        res.json(result);
    } else {
        res.status(400).send('Invalid input');
    }
});

app.listen(port, () => {
    console.log(`Server running at http://localhost:${port}`);
});

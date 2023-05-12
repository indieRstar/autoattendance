const socket = require('socket.io');
const https = require('https');
const fs = require('fs');

const HTTP_PORT = 8080;
const HTTPS_PORT = 8443;

const sslOptions = {
    key: fs.readFileSync('./rootca.key'),
    cert: fs.readFileSync('./rootca.crt')
};

const app = express();

app.get('/', (req, res) => {
    res.json({ message: `Server is running on port ${req.secure ? HTTPS_PORT : HTTP_PORT }`});
});

https.createServer(app).listen(HTTP_PORT);

https.createServer(sslOptions, app).listen(HTTPS_PORT);

//등록하시겠습니까? -> c++ 단 sqlite 서버로 보냄
//조회

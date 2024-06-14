from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route('/endpoint', methods=['POST'])
def receive_data():
    data = request.json
    if not data:
        return jsonify({"error": "Invalid data"}), 400

    distance = data.get('distance')

    if distance is None:
        return jsonify({"error": "Missing data"}), 400

    # Log data or process it as needed
    print(f"Received distance: {distance}")

    return jsonify({"message": "Data received successfully"}), 200

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)

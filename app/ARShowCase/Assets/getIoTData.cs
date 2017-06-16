using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using SocketIO;

public class getIoTData : MonoBehaviour {
	SocketIOComponent socket;
	TextMesh sensorDataText;
	// Use this for initialization
	void Start () {
		sensorDataText = GetComponent<TextMesh> ();
		//socket = GetComponent<SocketIOComponent> ();
		GameObject go = GameObject.Find("SocketIO");
		SocketIOComponent socket = go.GetComponent<SocketIOComponent>();

		socket.On ("open", TestOpen);
		socket.On ("error", TestError);
		socket.On ("close", TestClose);
		socket.On ("data", SocketEventHandler);
		socket.Emit ("start:0");
	}
	
	// Update is called once per frame
	void Update () {
		
	}

	public void SocketEventHandler(SocketIOEvent e) {
		Debug.Log("[SocketIO] Message received: " + e.name + " " + e.data);
		sensorDataText.text = e.data.ToString();
	}

	public void TestOpen(SocketIOEvent e)
	{
		Debug.Log("[SocketIO] Open received: " + e.name + " " + e.data);
		socket.Emit ("hello:{}");
	}

	public void TestError(SocketIOEvent e)
	{
		
		Debug.Log("[SocketIO] Error received: " + e.name + " " + e.data);
	}

	public void TestClose(SocketIOEvent e)
	{	
		Debug.Log("[SocketIO] Close received: " + e.name + " " + e.data);
	}
}

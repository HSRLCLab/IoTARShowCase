using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;

//using System.Web;

//[Serializable]
public class SensorData
{
	public int angle;
}

public class getIoTData : MonoBehaviour {
	
	TextMesh sensorDataText;
	string url = "http://192.168.192.9:1880/sensordata";
	bool requesting = false;
	// Use this for initialization
	void Start () {
		sensorDataText = GetComponent<TextMesh> ();
		sensorDataText.text = "init";
		StartCoroutine (getSensorData ());
	}
	
	// Update is called once per frame
	void Update () {
		if (!requesting) {
			StartCoroutine (getSensorData ());
		}
	}

	IEnumerator getSensorData()
	{
		this.requesting = true;
		using (UnityWebRequest www = UnityWebRequest.Get(url))
		{
			yield return www.Send();

			if (www.isError)
			{
				Debug.Log(www.error);
			}
			else
			{
				// Show results as text
				Debug.Log(www.downloadHandler.text);
				SensorData data = JsonUtility.FromJson<SensorData>(www.downloadHandler.text);
				sensorDataText.text = data.angle + "°";
			}
			this.requesting = false;
		}
	}

}

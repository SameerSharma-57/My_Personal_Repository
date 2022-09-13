using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BoomerangForPlayer : MonoBehaviour
{
    public GameObject boomer;
    public bool isThrown;


    // Use this for initialization
    void Start()
    {
        isThrown = false;
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Mouse0)&& !isThrown)
        {
            isThrown=true;
            GameObject clone;
            clone = Instantiate(boomer, new Vector3(transform.position.x, transform.position.y + 1, transform.position.z)+1*transform.right, transform.rotation) as GameObject;
        }
    }
}

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class boomerang : MonoBehaviour
{
    bool go;//Will Be Used To Change Direction Of Weapon
    bool isThrown;
    public float waitTime = 1.5f;
    public BoomerangForPlayer bfp;
    Camera cam;

    playerController player;//Reference To The Main Character
    //boomerang sword;//Reference To The Main Character's Weapon

    Transform itemToRotate;//The Weapon That Is A Child Of The Empty Game Object

    Vector3 locationInFrontOfPlayer;//Location In Front Of Player To Travel To


    // Use this for initialization
    void Start()
    {
        go = false; //Set To Not Return Yet
        bfp = FindObjectOfType<BoomerangForPlayer>();

        player = FindObjectOfType<playerController>();
        cam=FindObjectOfType<Camera>();
        // The GameObject To Return To
        //sword = FindObjectOfType<boomerang>();//The Weapon The Character Is Holding In The Scene

        //sword.GetComponent<MeshRenderer>().enabled = false; //Turn Off The Mesh Render To Make The Weapon Invisible

        itemToRotate = gameObject.transform.GetChild(0); //Find The Weapon That Is The Child Of The Empty Object       

        //Adjust The Location Of The Player Accordingly, Here I Add To The Y position So That The Object Doesn't Go Too Low ...Also Pick A Location In Front Of The Player
        //locationInFrontOfPlayer = new Vector3(player.transform.position.x, player.transform.position.y + 1, player.transform.position.z) + player.transform.forward * 10f;
        locationInFrontOfPlayer = new Vector3(player.transform.position.x, player.transform.position.y + 1, player.transform.position.z) + cam.transform.forward * 10f;

        StartCoroutine(Boom());//Now Start The Coroutine
    }

    IEnumerator Boom()
    {
        
        go = true;
        
        yield return new WaitForSeconds(waitTime);//Any Amount Of Time You Want
        go = false;
        
    }


    // Update is called once per frame
    void Update()
    {
        itemToRotate.transform.Rotate(0, Time.deltaTime * 500, 0); //Rotate The Object

        if (go)
        {
            transform.position = Vector3.MoveTowards(transform.position, locationInFrontOfPlayer, Time.deltaTime * 40); //Change The Position To The Location In Front Of The Player            
        }

        if (!go)
        {
            transform.position = Vector3.MoveTowards(transform.position, new Vector3(player.transform.position.x+1, player.transform.position.y + 1, player.transform.position.z), Time.deltaTime * 40); //Return To Player
        }

        if (!go && Vector3.Distance(player.transform.position, transform.position) < 1.5)
        {
            //Once It Is Close To The Player, Make The Player's Normal Weapon Visible, and Destroy The Clone
            //sword.GetComponent<MeshRenderer>().enabled = true;
            bfp.isThrown=false;
            Destroy(this.gameObject);
            
        }
    }
}

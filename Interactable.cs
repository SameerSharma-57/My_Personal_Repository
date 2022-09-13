using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Interactable : MonoBehaviour
{
    public float radius = 3f;
    bool isfocus = false;
    bool hasInteracted = false;
    Transform player;

    public void Onfocused(Transform playerTransform)
    {
        isfocus = true;
        player = playerTransform;
        hasInteracted = false;
    }

    public void Defocused()
    {
        isfocus=false; 
        player = null;
    }
    private void OnDrawGizmosSelected()
    {
        Gizmos.color = Color.yellow;
        Gizmos.DrawWireSphere(transform.position, radius);
    }

    private void Update()
    {
        if (isfocus && !hasInteracted)
        {
            float dis=Vector3.Distance(transform.position, player.position);
            if (dis <= radius)
            {
                hasInteracted = true;
                Interact();
            }
            
        }
    }

    public virtual void Interact()
    {
        Debug.Log("INTERACT");
    }
}

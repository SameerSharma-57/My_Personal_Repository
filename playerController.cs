

using UnityEngine;

public class playerController : MonoBehaviour
{
    public Interactable focus = null;
    
    private void SetFocus(Interactable interactable)
    {
        if (focus != interactable)
        {
            if(focus != null)
            {
                focus.Defocused();
            }
            focus = interactable;

        }
        
        focus.Onfocused(transform);
        //Debug.Log("focus is " + interactable.name);
    }
    public void RemoveFocus()
    {
        if (focus != null)
        {
            focus.Defocused();
            focus = null;
            Debug.Log("focus is NULL");
        }
    }

    // Update is called once per frame
    void Update()

    {
       

        Cursor.visible = true;
        Cursor.lockState = CursorLockMode.None;
        if (Input.GetMouseButtonDown(1))
        {
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            RaycastHit hit;
            if (Physics.Raycast(ray, out hit, 100))
            {
                Interactable interactable = hit.collider.GetComponent<Interactable>();
                if (interactable != null)
                {
                    SetFocus(interactable);
                    
                }
            }
        }

    }
}

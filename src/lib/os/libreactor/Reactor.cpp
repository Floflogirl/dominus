#include <libreactor/Reactor.hpp>

//==============================================================================
//
// Cst/Dst
//
//==============================================================================
//------------------------------------------------------------------------------
// cst
//------------------------------------------------------------------------------
Reactor::Reactor() :
    _poll_items(nullptr)
{
}

//==============================================================================
//
// Public methods
//
//==============================================================================
//------------------------------------------------------------------------------
// register_event
//------------------------------------------------------------------------------
void Reactor::register_event(ReactorCallback *callback)
{
    _callbacks.push_back(callback);
}

//------------------------------------------------------------------------------
// unregister_event
//------------------------------------------------------------------------------
void Reactor::unregister_event(ReactorCallback *callback)
{
    for(size_t j=0; j<_callbacks.size(); j++)
        if(_callbacks[j] == callback)
        {
            _callbacks.erase(_callbacks.begin() + j);
            break;
        }
}

//------------------------------------------------------------------------------
// run
//------------------------------------------------------------------------------
void Reactor::run()
{
    build_poll_items();
}

//==============================================================================
//
// Private methods
//
//==============================================================================
//------------------------------------------------------------------------------
// build_poll_items
//------------------------------------------------------------------------------
void Reactor::build_poll_items()
{
    if(_poll_items != nullptr)
        delete [] _poll_items;
    
    _poll_items = new zmq_pollitem_t[_callbacks.size() + 1];

    for(size_t j=0; j<_callbacks.size(); j++)
        _poll_items[j] = _callbacks[j]->get_poll_item();
}
// Launch policies
future<int> fu = async(factorial, 4);
future<int> fu = async(launch::deferred, factorial, 4);
future<int> fu = async(launch::async, factorial, 4);
future<int> fu = async(launch::async | launch::deferred,factorial,4);

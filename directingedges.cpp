vector< pair<int,int> >v1;
        cnt=0;scnt=0;
        cin>>n>>d;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            v1.push_back( make_pair(arr[i],i));
        }
        sort(v1.begin(),v1.end());
        for(int i=0;i<n;i++)
        {
            if(abs(v1[i].first-arr[i])==d)
            {
                cnt++;
                arr[i]=arr[i]+arr[v1[i].second];
                arr[v1[i].second]=arr[i]-arr[v1[i].second];
                arr[i]=arr[i]-arr[v1[i].second];
                ind=lower_bound(v1.begin(),v1.end(),arr[v1[i].second])-v1.begin();
                cout<<ind<<endl;
                v1[ind].second=v1[i].second;
                v1[i].second=i;
            }
        }
        /*for(int i=0;i<n;i++)
            cout<<arr[i]<<endl;*/
        for(int i=0;i<n;i++)
        {
            if(v1[i].first==arr[i])
                scnt++;
        }
        cout<<cnt<<endl;
        if(scnt==n)
            cout<<cnt<<endl;
        else
            cout<<-1<<endl;
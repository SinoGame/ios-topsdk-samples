using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Linq;
using UnityEngine;

[SuppressMessage("ReSharper", "InconsistentNaming")]
public class TopSDKBase
{

    public static readonly string topSDKVersion = "1.3.0.1";
    private static string _pluginName;

    public static string PluginName
    {
        get { return _pluginName ?? (_pluginName = "TopSDK Unity Plugin v" + topSDKVersion); }
    }


    // Allocate the GamePlusManager singleton, which receives all callback events from the native SDKs.
    protected static void InitManager()
    {
        var type = typeof(TopSDKManager);
        var mgr = new GameObject("TopSDKManager", type).GetComponent<TopSDKManager>(); // Its Awake() method sets Instance.
        if (TopSDKManager.Instance != mgr)
            Debug.LogWarning(
                "It looks like you have the " + type.Name
                + " on a GameObject in your scene. Please remove the script from your scene.");
    }


    protected TopSDKBase() { }
}

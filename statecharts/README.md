# Build
Build https://github.com/jp-embedded/scxmlcc and run `scxmlcc flow.scxml.

Qt's own scxml tool is not supported due the dependecies to Qt. scmlcc uses plain new c++17 standard by default. Qt creator does have scxml editor build-in but is not totally compliant with scxmlcc. Qt creator includes some custom tags for positioning and root exit states which are not coompliant with scxmlcc. Sxcxmlcc is still able to generate code from the Qt IDE schemas. Just don't use non-supported features. 

.setcpu "65816"
.segment "CODE"
.org $1ADB
map_control_0f1adb:
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $ADB9
map_control_0dadb9:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count

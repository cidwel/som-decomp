.setcpu "65816"
.segment "CODE"
.org $C283
map_control_0ec283:
    .byte $E0 ; previous-row copy escape
    .byte $D8 ; row-distance/count

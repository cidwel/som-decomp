.setcpu "65816"
.segment "CODE"
.org $C304
map_control_0ec304:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count

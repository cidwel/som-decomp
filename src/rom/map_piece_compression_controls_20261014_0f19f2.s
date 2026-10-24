.setcpu "65816"
.segment "CODE"
.org $19F2
map_control_0f19f2:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $19F4
map_control_0c19f4:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count

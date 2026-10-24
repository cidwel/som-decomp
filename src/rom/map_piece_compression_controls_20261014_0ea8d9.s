.setcpu "65816"
.segment "CODE"
.org $A8D9
map_control_0ea8d9:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

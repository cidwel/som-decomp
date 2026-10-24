.setcpu "65816"
.segment "CODE"
.org $6AB7
map_control_0f6ab7:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

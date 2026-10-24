.setcpu "65816"
.segment "CODE"
.org $ECA8
map_control_0eeca8:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

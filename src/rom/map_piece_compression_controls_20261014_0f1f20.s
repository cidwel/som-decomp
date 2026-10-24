.setcpu "65816"
.segment "CODE"
.org $1F20
map_control_0f1f20:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

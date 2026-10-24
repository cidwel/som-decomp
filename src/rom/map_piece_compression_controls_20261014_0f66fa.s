.setcpu "65816"
.segment "CODE"
.org $66FA
map_control_0f66fa:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

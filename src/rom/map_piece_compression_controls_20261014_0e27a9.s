.setcpu "65816"
.segment "CODE"
.org $27A9
map_control_0e27a9:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

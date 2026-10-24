.setcpu "65816"
.segment "CODE"
.org $C07A
map_control_0dc07a:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

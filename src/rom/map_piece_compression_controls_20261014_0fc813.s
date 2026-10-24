.setcpu "65816"
.segment "CODE"
.org $C813
map_control_0fc813:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

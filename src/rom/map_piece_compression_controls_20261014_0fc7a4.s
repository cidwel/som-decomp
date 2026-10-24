.setcpu "65816"
.segment "CODE"
.org $C7A4
map_control_0fc7a4:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

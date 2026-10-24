.setcpu "65816"
.segment "CODE"
.org $C7D7
map_control_0fc7d7:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count

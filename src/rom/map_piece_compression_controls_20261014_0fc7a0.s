.setcpu "65816"
.segment "CODE"
.org $C7A0
map_control_0fc7a0:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count

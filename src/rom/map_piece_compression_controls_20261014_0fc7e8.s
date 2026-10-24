.setcpu "65816"
.segment "CODE"
.org $C7E8
map_control_0fc7e8:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count

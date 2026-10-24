.setcpu "65816"
.segment "CODE"
.org $C8D6
map_control_0fc8d6:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $C44F
map_control_0fc44f:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count

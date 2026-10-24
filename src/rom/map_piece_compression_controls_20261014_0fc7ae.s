.setcpu "65816"
.segment "CODE"
.org $C7AE
map_control_0fc7ae:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count

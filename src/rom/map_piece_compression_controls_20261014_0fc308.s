.setcpu "65816"
.segment "CODE"
.org $C308
map_control_0fc308:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $C49F
map_control_0fc49f:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count

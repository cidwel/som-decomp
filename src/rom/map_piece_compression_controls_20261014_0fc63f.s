.setcpu "65816"
.segment "CODE"
.org $C63F
map_control_0fc63f:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count

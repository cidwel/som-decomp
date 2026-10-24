.setcpu "65816"
.segment "CODE"
.org $C21F
map_control_0fc21f:
    .byte $E0 ; previous-row copy escape
    .byte $D0 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $C666
map_control_0fc666:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count

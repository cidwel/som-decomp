.setcpu "65816"
.segment "CODE"
.org $C654
map_control_0fc654:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count

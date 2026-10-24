.setcpu "65816"
.segment "CODE"
.org $C64D
map_control_0fc64d:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count

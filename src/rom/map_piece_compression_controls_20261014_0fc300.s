.setcpu "65816"
.segment "CODE"
.org $C300
map_control_0fc300:
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count

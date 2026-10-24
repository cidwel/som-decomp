.setcpu "65816"
.segment "CODE"
.org $C8BF
map_control_0fc8bf:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count

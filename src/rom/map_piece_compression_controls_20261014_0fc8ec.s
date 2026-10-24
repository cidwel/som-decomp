.setcpu "65816"
.segment "CODE"
.org $C8EC
map_control_0fc8ec:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count

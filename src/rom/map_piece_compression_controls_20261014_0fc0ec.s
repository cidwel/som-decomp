.setcpu "65816"
.segment "CODE"
.org $C0EC
map_control_0fc0ec:
    .byte $E0 ; previous-row copy escape
    .byte $44 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $C893
map_control_0fc893:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count

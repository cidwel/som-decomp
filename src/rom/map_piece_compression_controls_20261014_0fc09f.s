.setcpu "65816"
.segment "CODE"
.org $C09F
map_control_0fc09f:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count

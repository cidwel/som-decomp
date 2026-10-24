.setcpu "65816"
.segment "CODE"
.org $C794
map_control_0fc794:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count

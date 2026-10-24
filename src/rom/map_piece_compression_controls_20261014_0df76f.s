.setcpu "65816"
.segment "CODE"
.org $F76F
map_control_0df76f:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

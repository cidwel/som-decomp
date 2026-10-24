.setcpu "65816"
.segment "CODE"
.org $792F
map_control_0f792f:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

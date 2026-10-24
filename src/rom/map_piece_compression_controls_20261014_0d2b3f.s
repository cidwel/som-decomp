.setcpu "65816"
.segment "CODE"
.org $2B3F
map_control_0d2b3f:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

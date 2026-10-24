.setcpu "65816"
.segment "CODE"
.org $3FA7
map_control_0f3fa7:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

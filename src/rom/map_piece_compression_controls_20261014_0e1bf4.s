.setcpu "65816"
.segment "CODE"
.org $1BF4
map_control_0e1bf4:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

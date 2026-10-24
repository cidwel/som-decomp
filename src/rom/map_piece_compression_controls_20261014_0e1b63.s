.setcpu "65816"
.segment "CODE"
.org $1B63
map_control_0e1b63:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count

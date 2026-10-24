.setcpu "65816"
.segment "CODE"
.org $0DC7
map_control_0d0dc7:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count

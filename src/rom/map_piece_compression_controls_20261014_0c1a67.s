.setcpu "65816"
.segment "CODE"
.org $1A67
map_control_0c1a67:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count

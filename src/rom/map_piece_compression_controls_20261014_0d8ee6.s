.setcpu "65816"
.segment "CODE"
.org $8EE6
map_control_0d8ee6:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count

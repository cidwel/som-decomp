.setcpu "65816"
.segment "CODE"
.org $5431
map_control_0d5431:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count

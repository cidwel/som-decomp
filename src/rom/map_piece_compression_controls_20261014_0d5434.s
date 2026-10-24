.setcpu "65816"
.segment "CODE"
.org $5434
map_control_0d5434:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count

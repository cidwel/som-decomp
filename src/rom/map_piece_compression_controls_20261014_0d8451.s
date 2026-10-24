.setcpu "65816"
.segment "CODE"
.org $8451
map_control_0d8451:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count

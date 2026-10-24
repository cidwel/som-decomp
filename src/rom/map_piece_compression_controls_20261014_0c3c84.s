.setcpu "65816"
.segment "CODE"
.org $3C84
map_control_0c3c84:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count

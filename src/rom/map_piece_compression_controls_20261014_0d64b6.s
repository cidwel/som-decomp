.setcpu "65816"
.segment "CODE"
.org $64B6
map_control_0d64b6:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count

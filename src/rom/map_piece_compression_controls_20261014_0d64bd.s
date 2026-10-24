.setcpu "65816"
.segment "CODE"
.org $64BD
map_control_0d64bd:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count

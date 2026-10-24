.setcpu "65816"
.segment "CODE"
.org $C221
map_control_0dc221:
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count

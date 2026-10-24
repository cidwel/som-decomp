.setcpu "65816"
.segment "CODE"
.org $D309
map_control_0dd309:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count

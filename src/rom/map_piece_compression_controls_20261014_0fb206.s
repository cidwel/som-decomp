.setcpu "65816"
.segment "CODE"
.org $B206
map_control_0fb206:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count

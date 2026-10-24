.setcpu "65816"
.segment "CODE"
.org $40FB
map_control_0f40fb:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count

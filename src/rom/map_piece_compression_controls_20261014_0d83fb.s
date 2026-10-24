.setcpu "65816"
.segment "CODE"
.org $83FB
map_control_0d83fb:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count

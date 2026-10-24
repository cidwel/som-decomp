.setcpu "65816"
.segment "CODE"
.org $E066
map_control_0de066:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count

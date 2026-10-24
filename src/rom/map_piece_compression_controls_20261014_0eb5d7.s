.setcpu "65816"
.segment "CODE"
.org $B5D7
map_control_0eb5d7:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count

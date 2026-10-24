.setcpu "65816"
.segment "CODE"
.org $B4E6
map_control_0fb4e6:
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $B1DF
map_control_0fb1df:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count

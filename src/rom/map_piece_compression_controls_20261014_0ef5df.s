.setcpu "65816"
.segment "CODE"
.org $F5DF
map_control_0ef5df:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count

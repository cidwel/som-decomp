.setcpu "65816"
.segment "CODE"
.org $B6DF
map_control_0eb6df:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count

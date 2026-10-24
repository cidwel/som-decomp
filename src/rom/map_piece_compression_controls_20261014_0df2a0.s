.setcpu "65816"
.segment "CODE"
.org $F2A0
map_control_0df2a0:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count

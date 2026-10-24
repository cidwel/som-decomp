.setcpu "65816"
.segment "CODE"
.org $F2CF
map_control_0df2cf:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count

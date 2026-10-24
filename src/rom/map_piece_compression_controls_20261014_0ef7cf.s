.setcpu "65816"
.segment "CODE"
.org $F7CF
map_control_0ef7cf:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count

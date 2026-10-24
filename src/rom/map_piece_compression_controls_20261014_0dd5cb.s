.setcpu "65816"
.segment "CODE"
.org $D5CB
map_control_0dd5cb:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count

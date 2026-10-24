.setcpu "65816"
.segment "CODE"
.org $AAA4
map_control_0faaa4:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count

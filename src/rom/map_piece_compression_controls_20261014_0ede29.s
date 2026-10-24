.setcpu "65816"
.segment "CODE"
.org $DE29
map_control_0ede29:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $B448
map_control_0eb448:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $53EF
map_control_0e53ef:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count

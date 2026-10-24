.setcpu "65816"
.segment "CODE"
.org $F57C
map_control_0ef57c:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count

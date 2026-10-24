.setcpu "65816"
.segment "CODE"
.org $31EF
map_control_0c31ef:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count

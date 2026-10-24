.setcpu "65816"
.segment "CODE"
.org $31EF
map_control_0f31ef:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count

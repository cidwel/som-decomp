.setcpu "65816"
.segment "CODE"
.org $9269
map_control_0e9269:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count

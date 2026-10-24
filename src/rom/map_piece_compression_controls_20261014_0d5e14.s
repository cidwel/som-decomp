.setcpu "65816"
.segment "CODE"
.org $5E14
map_control_0d5e14:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count

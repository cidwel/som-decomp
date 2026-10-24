.setcpu "65816"
.segment "CODE"
.org $8E11
map_control_0d8e11:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count

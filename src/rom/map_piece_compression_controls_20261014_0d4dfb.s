.setcpu "65816"
.segment "CODE"
.org $4DFB
map_control_0d4dfb:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count

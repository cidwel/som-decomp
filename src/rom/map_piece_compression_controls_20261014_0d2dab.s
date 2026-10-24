.setcpu "65816"
.segment "CODE"
.org $2DAB
map_control_0d2dab:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count

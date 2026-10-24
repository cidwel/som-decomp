.setcpu "65816"
.segment "CODE"
.org $2DAB
map_control_0f2dab:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count

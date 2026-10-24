.setcpu "65816"
.segment "CODE"
.org $9484
map_control_0f9484:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count

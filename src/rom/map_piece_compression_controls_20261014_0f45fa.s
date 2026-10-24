.setcpu "65816"
.segment "CODE"
.org $45FA
map_control_0f45fa:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count

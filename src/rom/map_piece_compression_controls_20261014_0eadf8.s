.setcpu "65816"
.segment "CODE"
.org $ADF8
map_control_0eadf8:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count

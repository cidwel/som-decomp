.setcpu "65816"
.segment "CODE"
.org $AC84
map_control_0dac84:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count

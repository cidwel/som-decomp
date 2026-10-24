.setcpu "65816"
.segment "CODE"
.org $0ADC
map_control_0d0adc:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count

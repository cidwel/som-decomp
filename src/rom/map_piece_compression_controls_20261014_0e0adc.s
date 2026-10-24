.setcpu "65816"
.segment "CODE"
.org $0ADC
map_control_0e0adc:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count

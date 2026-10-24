.setcpu "65816"
.segment "CODE"
.org $0ADC
map_control_0f0adc:
    .byte $E7 ; previous-row copy count

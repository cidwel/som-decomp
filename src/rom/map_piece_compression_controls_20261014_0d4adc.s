.setcpu "65816"
.segment "CODE"
.org $4ADC
map_control_0d4adc:
    .byte $E1 ; previous-row copy count

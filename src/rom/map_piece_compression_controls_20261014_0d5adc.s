.setcpu "65816"
.segment "CODE"
.org $5ADC
map_control_0d5adc:
    .byte $E6 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $37 ; distance low bit/count

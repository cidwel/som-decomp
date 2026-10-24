.setcpu "65816"
.segment "CODE"
.org $3ADC
map_control_0f3adc:
    .byte $C2 ; same-value copy count/distance

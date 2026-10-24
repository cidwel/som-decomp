.setcpu "65816"
.segment "CODE"
.org $4ADC
map_control_0c4adc:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count

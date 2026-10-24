.setcpu "65816"
.segment "CODE"
.org $2ADC
map_control_0e2adc:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count

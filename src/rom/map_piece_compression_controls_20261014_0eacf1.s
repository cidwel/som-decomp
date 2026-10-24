.setcpu "65816"
.segment "CODE"
.org $ACF1
map_control_0eacf1:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $55BE
map_control_0e55be:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count

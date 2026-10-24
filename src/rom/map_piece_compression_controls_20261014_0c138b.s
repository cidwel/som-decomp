.setcpu "65816"
.segment "CODE"
.org $138B
map_control_0c138b:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count

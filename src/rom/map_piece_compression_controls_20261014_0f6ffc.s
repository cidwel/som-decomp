.setcpu "65816"
.segment "CODE"
.org $6FFC
map_control_0f6ffc:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count

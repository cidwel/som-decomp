.setcpu "65816"
.segment "CODE"
.org $8C14
map_control_0d8c14:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count

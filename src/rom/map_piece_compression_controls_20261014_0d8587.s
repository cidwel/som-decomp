.setcpu "65816"
.segment "CODE"
.org $8587
map_control_0d8587:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count

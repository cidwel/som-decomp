.setcpu "65816"
.segment "CODE"
.org $5D0B
map_control_0f5d0b:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count

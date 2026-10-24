.setcpu "65816"
.segment "CODE"
.org $6E8B
map_control_0f6e8b:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

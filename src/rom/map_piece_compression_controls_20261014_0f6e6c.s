.setcpu "65816"
.segment "CODE"
.org $6E6C
map_control_0f6e6c:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $8B6C
map_control_0d8b6c:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

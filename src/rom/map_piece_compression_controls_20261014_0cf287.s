.setcpu "65816"
.segment "CODE"
.org $F287
map_control_0cf287:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count

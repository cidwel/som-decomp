.setcpu "65816"
.segment "CODE"
.org $502B
map_control_0e502b:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

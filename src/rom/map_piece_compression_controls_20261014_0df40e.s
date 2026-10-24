.setcpu "65816"
.segment "CODE"
.org $F40E
map_control_0df40e:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

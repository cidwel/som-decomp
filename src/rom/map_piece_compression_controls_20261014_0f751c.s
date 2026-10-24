.setcpu "65816"
.segment "CODE"
.org $751C
map_control_0f751c:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

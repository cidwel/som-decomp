.setcpu "65816"
.segment "CODE"
.org $3164
map_control_0c3164:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count

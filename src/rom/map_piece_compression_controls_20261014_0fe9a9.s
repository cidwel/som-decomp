.setcpu "65816"
.segment "CODE"
.org $E9A9
map_control_0fe9a9:
    .byte $E9 ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count

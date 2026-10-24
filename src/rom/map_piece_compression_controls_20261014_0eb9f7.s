.setcpu "65816"
.segment "CODE"
.org $B9F7
map_control_0eb9f7:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count

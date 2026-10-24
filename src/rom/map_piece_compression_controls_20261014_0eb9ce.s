.setcpu "65816"
.segment "CODE"
.org $B9CE
map_control_0eb9ce:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count

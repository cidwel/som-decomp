.setcpu "65816"
.segment "CODE"
.org $507E
map_control_0e507e:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count

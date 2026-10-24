.setcpu "65816"
.segment "CODE"
.org $F5E6
map_control_0df5e6:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count

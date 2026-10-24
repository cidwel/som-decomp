.setcpu "65816"
.segment "CODE"
.org $A843
map_control_0da843:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count

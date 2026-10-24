.setcpu "65816"
.segment "CODE"
.org $ED7E
map_control_0ded7e:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count

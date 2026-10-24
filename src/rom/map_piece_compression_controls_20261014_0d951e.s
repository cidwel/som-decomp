.setcpu "65816"
.segment "CODE"
.org $951E
map_control_0d951e:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count

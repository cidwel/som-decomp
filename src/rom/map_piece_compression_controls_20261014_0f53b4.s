.setcpu "65816"
.segment "CODE"
.org $53B4
map_control_0f53b4:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count

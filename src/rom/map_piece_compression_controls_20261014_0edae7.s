.setcpu "65816"
.segment "CODE"
.org $DAE7
map_control_0edae7:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $87 ; distance low bit/count

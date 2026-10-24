.setcpu "65816"
.segment "CODE"
.org $70DA
map_control_0e70da:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $52 ; distance low bit/count

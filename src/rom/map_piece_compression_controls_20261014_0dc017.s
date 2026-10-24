.setcpu "65816"
.segment "CODE"
.org $C017
map_control_0dc017:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count

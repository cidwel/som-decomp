.setcpu "65816"
.segment "CODE"
.org $8030
map_control_0d8030:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $CFFD
map_control_0fcffd:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $2B04
map_control_0d2b04:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

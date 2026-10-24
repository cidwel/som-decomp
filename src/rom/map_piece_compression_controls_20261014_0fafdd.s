.setcpu "65816"
.segment "CODE"
.org $AFDD
map_control_0fafdd:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

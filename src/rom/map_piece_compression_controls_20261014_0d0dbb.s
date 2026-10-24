.setcpu "65816"
.segment "CODE"
.org $0DBB
map_control_0d0dbb:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count

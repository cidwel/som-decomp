.setcpu "65816"
.segment "CODE"
.org $4570
map_control_0f4570:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

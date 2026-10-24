.setcpu "65816"
.segment "CODE"
.org $281C
map_control_0e281c:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

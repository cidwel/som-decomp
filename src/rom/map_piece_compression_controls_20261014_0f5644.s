.setcpu "65816"
.segment "CODE"
.org $5644
map_control_0f5644:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

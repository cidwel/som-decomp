.setcpu "65816"
.segment "CODE"
.org $5C41
map_control_0f5c41:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

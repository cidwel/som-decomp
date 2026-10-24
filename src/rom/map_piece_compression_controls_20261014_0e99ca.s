.setcpu "65816"
.segment "CODE"
.org $99CA
map_control_0e99ca:
    .byte $ED ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count

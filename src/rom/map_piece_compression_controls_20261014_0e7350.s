.setcpu "65816"
.segment "CODE"
.org $7350
map_control_0e7350:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count

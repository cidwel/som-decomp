.setcpu "65816"
.segment "CODE"
.org $4F60
map_control_0d4f60:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count

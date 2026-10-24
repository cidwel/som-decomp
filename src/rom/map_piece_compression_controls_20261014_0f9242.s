.setcpu "65816"
.segment "CODE"
.org $9242
map_control_0f9242:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $5224
map_control_0d5224:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count

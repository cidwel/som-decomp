.setcpu "65816"
.segment "CODE"
.org $533A
map_control_0c533a:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count

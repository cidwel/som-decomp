.setcpu "65816"
.segment "CODE"
.org $930C
map_control_0f930c:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count

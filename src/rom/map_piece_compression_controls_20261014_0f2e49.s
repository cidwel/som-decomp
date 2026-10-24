.setcpu "65816"
.segment "CODE"
.org $2E49
map_control_0f2e49:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $1339
map_control_0f1339:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count

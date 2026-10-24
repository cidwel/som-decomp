.setcpu "65816"
.segment "CODE"
.org $5401
map_control_0f5401:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $5401
map_control_0c5401:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count

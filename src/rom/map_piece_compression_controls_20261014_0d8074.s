.setcpu "65816"
.segment "CODE"
.org $8074
map_control_0d8074:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count

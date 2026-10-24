.setcpu "65816"
.segment "CODE"
.org $7AFD
map_control_0f7afd:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count

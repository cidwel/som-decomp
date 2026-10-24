.setcpu "65816"
.segment "CODE"
.org $4FCC
map_control_0d4fcc:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count

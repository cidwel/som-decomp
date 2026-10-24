.setcpu "65816"
.segment "CODE"
.org $ADE3
map_control_0dade3:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $7C14
map_control_0f7c14:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count

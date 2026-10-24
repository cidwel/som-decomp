.setcpu "65816"
.segment "CODE"
.org $25DB
map_control_0f25db:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $4BBC
map_control_0c4bbc:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count

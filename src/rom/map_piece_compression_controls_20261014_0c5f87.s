.setcpu "65816"
.segment "CODE"
.org $5F87
map_control_0c5f87:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count

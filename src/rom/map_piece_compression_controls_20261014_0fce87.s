.setcpu "65816"
.segment "CODE"
.org $CE87
map_control_0fce87:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count

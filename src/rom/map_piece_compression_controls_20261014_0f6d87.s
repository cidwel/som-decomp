.setcpu "65816"
.segment "CODE"
.org $6D87
map_control_0f6d87:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count

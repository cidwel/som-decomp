.setcpu "65816"
.segment "CODE"
.org $9F87
map_control_0f9f87:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count

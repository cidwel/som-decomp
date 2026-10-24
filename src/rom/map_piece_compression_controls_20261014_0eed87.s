.setcpu "65816"
.segment "CODE"
.org $ED87
map_control_0eed87:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count

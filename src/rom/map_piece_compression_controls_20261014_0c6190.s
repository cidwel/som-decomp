.setcpu "65816"
.segment "CODE"
.org $6190
map_control_0c6190:
    .byte $F3 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count

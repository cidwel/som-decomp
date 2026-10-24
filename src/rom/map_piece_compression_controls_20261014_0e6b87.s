.setcpu "65816"
.segment "CODE"
.org $6B87
map_control_0e6b87:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count

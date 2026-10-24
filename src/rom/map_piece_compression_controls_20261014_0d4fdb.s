.setcpu "65816"
.segment "CODE"
.org $4FDB
map_control_0d4fdb:
    .byte $F1 ; progressive-copy count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count

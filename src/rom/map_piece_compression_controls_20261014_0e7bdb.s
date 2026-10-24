.setcpu "65816"
.segment "CODE"
.org $7BDB
map_control_0e7bdb:
    .byte $F1 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count

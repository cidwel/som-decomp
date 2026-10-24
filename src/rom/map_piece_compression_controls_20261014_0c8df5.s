.setcpu "65816"
.segment "CODE"
.org $8DF5
map_control_0c8df5:
    .byte $F3 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count

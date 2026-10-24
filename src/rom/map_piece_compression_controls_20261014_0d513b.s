.setcpu "65816"
.segment "CODE"
.org $513B
map_control_0d513b:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count

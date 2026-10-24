.setcpu "65816"
.segment "CODE"
.org $5197
map_control_0d5197:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count

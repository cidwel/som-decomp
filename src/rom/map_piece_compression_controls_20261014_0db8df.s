.setcpu "65816"
.segment "CODE"
.org $B8DF
map_control_0db8df:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count

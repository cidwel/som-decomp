.setcpu "65816"
.segment "CODE"
.org $24BF
map_control_0d24bf:
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count

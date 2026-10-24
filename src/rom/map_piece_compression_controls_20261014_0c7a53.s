.setcpu "65816"
.segment "CODE"
.org $7A53
map_control_0c7a53:
    .byte $F1 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count

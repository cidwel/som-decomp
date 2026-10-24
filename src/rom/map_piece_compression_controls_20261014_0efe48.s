.setcpu "65816"
.segment "CODE"
.org $FE48
map_control_0efe48:
    .byte $F2 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count

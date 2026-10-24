.setcpu "65816"
.segment "CODE"
.org $80CF
map_control_0f80cf:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $05 ; distance low bit/count

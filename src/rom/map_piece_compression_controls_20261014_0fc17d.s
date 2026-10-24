.setcpu "65816"
.segment "CODE"
.org $C17D
map_control_0fc17d:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $C5 ; same-value copy count/distance

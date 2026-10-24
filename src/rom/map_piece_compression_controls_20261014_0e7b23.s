.setcpu "65816"
.segment "CODE"
.org $7B23
map_control_0e7b23:
    .byte $F1 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance

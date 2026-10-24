.setcpu "65816"
.segment "CODE"
.org $8365
map_control_0d8365:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $C3 ; same-value copy count/distance

.setcpu "65816"
.segment "CODE"
.org $096C
map_control_0f096c:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count

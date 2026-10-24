.setcpu "65816"
.segment "CODE"
.org $498B
map_control_0e498b:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance

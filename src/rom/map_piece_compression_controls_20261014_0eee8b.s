.setcpu "65816"
.segment "CODE"
.org $EE8B
map_control_0eee8b:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $C2 ; same-value copy count/distance

.setcpu "65816"
.segment "CODE"
.org $4775
map_control_0e4775:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $8C ; distance low bit/count

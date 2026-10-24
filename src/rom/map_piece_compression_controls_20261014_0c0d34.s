.setcpu "65816"
.segment "CODE"
.org $0D34
map_control_0c0d34:
    .byte $EB ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $F1 ; progressive-copy count
    .byte $D5 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count

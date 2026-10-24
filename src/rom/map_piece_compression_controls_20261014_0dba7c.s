.setcpu "65816"
.segment "CODE"
.org $BA7C
map_control_0dba7c:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $C5 ; same-value copy count/distance

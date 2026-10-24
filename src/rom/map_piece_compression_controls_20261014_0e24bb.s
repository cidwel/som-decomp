.setcpu "65816"
.segment "CODE"
.org $24BB
map_control_0e24bb:
    .byte $C3 ; same-value copy count/distance
    .byte $F4 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count

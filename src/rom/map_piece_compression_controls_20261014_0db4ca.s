.setcpu "65816"
.segment "CODE"
.org $B4CA
map_control_0db4ca:
    .byte $EC ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $28 ; distance low bit/count

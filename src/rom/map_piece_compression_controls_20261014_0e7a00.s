.setcpu "65816"
.segment "CODE"
.org $7A00
map_control_0e7a00:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance

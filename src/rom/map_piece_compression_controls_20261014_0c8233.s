.setcpu "65816"
.segment "CODE"
.org $8233
map_control_0c8233:
    .byte $D2 ; same-value copy count/distance
    .byte $DA ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $8F ; distance low bit/count

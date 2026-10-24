.setcpu "65816"
.segment "CODE"
.org $D055
map_control_0fd055:
    .byte $D1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count

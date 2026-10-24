.setcpu "65816"
.segment "CODE"
.org $7CBE
map_control_0e7cbe:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance

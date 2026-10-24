.setcpu "65816"
.segment "CODE"
.org $931B
map_control_0f931b:
    .byte $D1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count

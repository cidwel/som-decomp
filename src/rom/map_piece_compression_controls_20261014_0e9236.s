.setcpu "65816"
.segment "CODE"
.org $9236
map_control_0e9236:
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $64 ; distance low bit/count

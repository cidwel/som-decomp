.setcpu "65816"
.segment "CODE"
.org $5EAE
map_control_0d5eae:
    .byte $C6 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $2A ; distance low bit/count

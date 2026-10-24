.setcpu "65816"
.segment "CODE"
.org $9111
map_control_0c9111:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count

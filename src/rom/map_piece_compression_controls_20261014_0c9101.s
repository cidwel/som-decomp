.setcpu "65816"
.segment "CODE"
.org $9101
map_control_0c9101:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count

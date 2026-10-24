.setcpu "65816"
.segment "CODE"
.org $ED9B
map_control_0fed9b:
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $90 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $90 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance

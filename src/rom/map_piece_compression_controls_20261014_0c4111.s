.setcpu "65816"
.segment "CODE"
.org $4111
map_control_0c4111:
    .byte $DA ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count

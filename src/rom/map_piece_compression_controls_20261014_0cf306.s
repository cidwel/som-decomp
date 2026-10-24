.setcpu "65816"
.segment "CODE"
.org $F306
map_control_0cf306:
    .byte $CB ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count

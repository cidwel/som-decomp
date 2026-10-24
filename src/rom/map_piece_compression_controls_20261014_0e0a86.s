.setcpu "65816"
.segment "CODE"
.org $0A86
map_control_0e0a86:
    .byte $F3 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance

.setcpu "65816"
.segment "CODE"
.org $8A39
map_control_0e8a39:
    .byte $EC ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance

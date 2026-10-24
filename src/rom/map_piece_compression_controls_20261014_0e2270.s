.setcpu "65816"
.segment "CODE"
.org $2270
map_control_0e2270:
    .byte $D1 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count

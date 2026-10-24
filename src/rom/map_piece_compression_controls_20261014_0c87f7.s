.setcpu "65816"
.segment "CODE"
.org $87F7
map_control_0c87f7:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance

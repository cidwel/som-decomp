.setcpu "65816"
.segment "CODE"
.org $73BB
map_control_0d73bb:
    .byte $EE ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance

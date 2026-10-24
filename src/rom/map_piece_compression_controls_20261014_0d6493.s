.setcpu "65816"
.segment "CODE"
.org $6493
map_control_0d6493:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count

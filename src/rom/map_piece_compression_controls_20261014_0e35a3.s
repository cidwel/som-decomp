.setcpu "65816"
.segment "CODE"
.org $35A3
map_control_0e35a3:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E5 ; previous-row copy count

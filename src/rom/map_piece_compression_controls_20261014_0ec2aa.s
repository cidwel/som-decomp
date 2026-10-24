.setcpu "65816"
.segment "CODE"
.org $C2AA
map_control_0ec2aa:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E3 ; previous-row copy count

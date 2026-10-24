.setcpu "65816"
.segment "CODE"
.org $430E
map_control_0e430e:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count

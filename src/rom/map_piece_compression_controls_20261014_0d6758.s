.setcpu "65816"
.segment "CODE"
.org $6758
map_control_0d6758:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E3 ; previous-row copy count

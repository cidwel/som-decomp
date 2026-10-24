.setcpu "65816"
.segment "CODE"
.org $7A13
map_control_0e7a13:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance

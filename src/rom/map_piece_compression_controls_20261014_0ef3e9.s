.setcpu "65816"
.segment "CODE"
.org $F3E9
map_control_0ef3e9:
    .byte $C3 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $31 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count

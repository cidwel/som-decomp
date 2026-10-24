.setcpu "65816"
.segment "CODE"
.org $66F4
map_control_0d66f4:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $D1 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count

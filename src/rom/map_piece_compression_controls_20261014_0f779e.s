.setcpu "65816"
.segment "CODE"
.org $779E
map_control_0f779e:
    .byte $ED ; backreference distance high bits
    .byte $96 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $F1 ; progressive-copy count
    .byte $D1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count

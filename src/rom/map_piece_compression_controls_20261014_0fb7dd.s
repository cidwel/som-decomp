.setcpu "65816"
.segment "CODE"
.org $B7DD
map_control_0fb7dd:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count

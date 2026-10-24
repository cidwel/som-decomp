.setcpu "65816"
.segment "CODE"
.org $FA55
map_control_0efa55:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count

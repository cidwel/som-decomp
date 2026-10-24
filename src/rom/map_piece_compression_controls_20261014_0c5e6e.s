.setcpu "65816"
.segment "CODE"
.org $5E6E
map_control_0c5e6e:
    .byte $F2 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count

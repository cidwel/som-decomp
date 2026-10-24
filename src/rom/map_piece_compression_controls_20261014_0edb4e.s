.setcpu "65816"
.segment "CODE"
.org $DB4E
map_control_0edb4e:
    .byte $E9 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count

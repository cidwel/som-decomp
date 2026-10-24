.setcpu "65816"
.segment "CODE"
.org $418E
map_control_0c418e:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
    .byte $E2 ; previous-row copy count

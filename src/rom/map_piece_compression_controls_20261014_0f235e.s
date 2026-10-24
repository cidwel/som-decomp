.setcpu "65816"
.segment "CODE"
.org $235E
map_control_0f235e:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count

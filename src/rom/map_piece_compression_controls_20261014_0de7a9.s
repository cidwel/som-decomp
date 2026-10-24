.setcpu "65816"
.segment "CODE"
.org $E7A9
map_control_0de7a9:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E4 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E4 ; previous-row copy count

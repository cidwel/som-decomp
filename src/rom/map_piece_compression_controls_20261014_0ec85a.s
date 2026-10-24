.setcpu "65816"
.segment "CODE"
.org $C85A
map_control_0ec85a:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E6 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count

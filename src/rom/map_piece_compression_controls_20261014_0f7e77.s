.setcpu "65816"
.segment "CODE"
.org $7E77
map_control_0f7e77:
    .byte $E7 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $7895
map_control_0f7895:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count

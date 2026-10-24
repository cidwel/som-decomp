.setcpu "65816"
.segment "CODE"
.org $7F06
map_control_0f7f06:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E2 ; previous-row copy count

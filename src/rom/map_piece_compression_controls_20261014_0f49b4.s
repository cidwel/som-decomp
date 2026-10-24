.setcpu "65816"
.segment "CODE"
.org $49B4
map_control_0f49b4:
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E2 ; previous-row copy count

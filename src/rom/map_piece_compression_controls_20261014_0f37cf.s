.setcpu "65816"
.segment "CODE"
.org $37CF
map_control_0f37cf:
    .byte $ED ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E3 ; previous-row copy count

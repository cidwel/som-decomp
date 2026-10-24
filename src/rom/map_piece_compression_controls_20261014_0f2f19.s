.setcpu "65816"
.segment "CODE"
.org $2F19
map_control_0f2f19:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E2 ; previous-row copy count

.setcpu "65816"
.segment "CODE"
.org $B324
map_control_0db324:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E2 ; previous-row copy count

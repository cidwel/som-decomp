.setcpu "65816"
.segment "CODE"
.org $E2B2
map_control_0de2b2:
    .byte $E2 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count

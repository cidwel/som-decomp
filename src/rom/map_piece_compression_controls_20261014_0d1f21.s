.setcpu "65816"
.segment "CODE"
.org $1F21
map_control_0d1f21:
    .byte $E2 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count

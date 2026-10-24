.setcpu "65816"
.segment "CODE"
.org $2B88
map_control_0f2b88:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
    .byte $E2 ; previous-row copy count

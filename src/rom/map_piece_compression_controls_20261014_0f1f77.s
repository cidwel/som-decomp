.setcpu "65816"
.segment "CODE"
.org $1F77
map_control_0f1f77:
    .byte $E2 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count

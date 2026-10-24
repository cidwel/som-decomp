.setcpu "65816"
.segment "CODE"
.org $1F8F
map_control_0f1f8f:
    .byte $E2 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count

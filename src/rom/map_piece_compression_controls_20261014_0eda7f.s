.setcpu "65816"
.segment "CODE"
.org $DA7F
map_control_0eda7f:
    .byte $E2 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count

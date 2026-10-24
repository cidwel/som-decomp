.setcpu "65816"
.segment "CODE"
.org $853D
map_control_0f853d:
    .byte $E9 ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E2 ; previous-row copy count

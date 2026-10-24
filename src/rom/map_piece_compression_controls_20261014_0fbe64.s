.setcpu "65816"
.segment "CODE"
.org $BE64
map_control_0fbe64:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E7 ; previous-row copy count

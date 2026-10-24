.setcpu "65816"
.segment "CODE"
.org $5749
map_control_0f5749:
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count

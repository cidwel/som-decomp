.setcpu "65816"
.segment "CODE"
.org $5654
map_control_0f5654:
    .byte $E5 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count

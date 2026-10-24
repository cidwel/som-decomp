.setcpu "65816"
.segment "CODE"
.org $39CD
map_control_0f39cd:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E2 ; previous-row copy count

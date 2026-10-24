.setcpu "65816"
.segment "CODE"
.org $6D1C
map_control_0f6d1c:
    .byte $E9 ; backreference distance high bits
    .byte $92 ; distance low bit/count
    .byte $E1 ; previous-row copy count

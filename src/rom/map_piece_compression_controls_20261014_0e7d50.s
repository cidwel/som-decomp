.setcpu "65816"
.segment "CODE"
.org $7D50
map_control_0e7d50:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E5 ; previous-row copy count

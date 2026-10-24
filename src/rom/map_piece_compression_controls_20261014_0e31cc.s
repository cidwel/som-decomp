.setcpu "65816"
.segment "CODE"
.org $31CC
map_control_0e31cc:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E3 ; previous-row copy count

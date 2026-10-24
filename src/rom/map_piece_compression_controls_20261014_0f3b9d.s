.setcpu "65816"
.segment "CODE"
.org $3B9D
map_control_0f3b9d:
    .byte $E3 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count

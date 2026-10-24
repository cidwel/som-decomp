.setcpu "65816"
.segment "CODE"
.org $4B42
map_control_0d4b42:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E5 ; previous-row copy count

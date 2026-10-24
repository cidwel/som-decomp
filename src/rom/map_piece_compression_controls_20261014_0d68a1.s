.setcpu "65816"
.segment "CODE"
.org $68A1
map_control_0d68a1:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E7 ; previous-row copy count

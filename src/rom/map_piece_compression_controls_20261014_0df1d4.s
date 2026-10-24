.setcpu "65816"
.segment "CODE"
.org $F1D4
map_control_0df1d4:
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count

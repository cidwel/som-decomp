.setcpu "65816"
.segment "CODE"
.org $3A63
map_control_0d3a63:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count

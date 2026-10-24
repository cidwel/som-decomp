.setcpu "65816"
.segment "CODE"
.org $6D63
map_control_0e6d63:
    .byte $E5 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count

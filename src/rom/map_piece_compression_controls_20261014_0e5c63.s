.setcpu "65816"
.segment "CODE"
.org $5C63
map_control_0e5c63:
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count

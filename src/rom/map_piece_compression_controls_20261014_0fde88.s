.setcpu "65816"
.segment "CODE"
.org $DE88
map_control_0fde88:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count

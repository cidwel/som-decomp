.setcpu "65816"
.segment "CODE"
.org $0D23
map_control_0d0d23:
    .byte $E0 ; previous-row copy escape
    .byte $B6 ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $0CD8
map_control_0d0cd8:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $B3 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $F13F
map_control_0cf13f:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count

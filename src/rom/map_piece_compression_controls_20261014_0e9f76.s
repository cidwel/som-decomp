.setcpu "65816"
.segment "CODE"
.org $9F76
map_control_0e9f76:
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $34D0
map_control_0e34d0:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count

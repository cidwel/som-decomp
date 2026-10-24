.setcpu "65816"
.segment "CODE"
.org $12D0
map_control_0e12d0:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count

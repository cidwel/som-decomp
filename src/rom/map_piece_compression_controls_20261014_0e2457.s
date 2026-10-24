.setcpu "65816"
.segment "CODE"
.org $2457
map_control_0e2457:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count

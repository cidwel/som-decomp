.setcpu "65816"
.segment "CODE"
.org $7C2F
map_control_0d7c2f:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count

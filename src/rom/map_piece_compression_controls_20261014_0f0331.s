.setcpu "65816"
.segment "CODE"
.org $0331
map_control_0f0331:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $68 ; row-distance/count

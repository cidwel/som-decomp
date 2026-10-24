.setcpu "65816"
.segment "CODE"
.org $4D49
map_control_0d4d49:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $58 ; row-distance/count

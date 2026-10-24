.setcpu "65816"
.segment "CODE"
.org $CA26
map_control_0dca26:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7C ; row-distance/count

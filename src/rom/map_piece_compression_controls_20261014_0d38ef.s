.setcpu "65816"
.segment "CODE"
.org $38EF
map_control_0d38ef:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count

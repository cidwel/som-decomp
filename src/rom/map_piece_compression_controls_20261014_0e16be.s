.setcpu "65816"
.segment "CODE"
.org $16BE
map_control_0e16be:
    .byte $E0 ; previous-row copy escape
    .byte $9C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count

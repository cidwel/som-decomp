.setcpu "65816"
.segment "CODE"
.org $7681
map_control_0d7681:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count

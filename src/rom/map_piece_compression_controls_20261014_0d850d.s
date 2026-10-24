.setcpu "65816"
.segment "CODE"
.org $850D
map_control_0d850d:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count

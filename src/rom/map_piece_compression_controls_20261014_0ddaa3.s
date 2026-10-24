.setcpu "65816"
.segment "CODE"
.org $DAA3
map_control_0ddaa3:
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count

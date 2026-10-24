.setcpu "65816"
.segment "CODE"
.org $2E74
map_control_0d2e74:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count

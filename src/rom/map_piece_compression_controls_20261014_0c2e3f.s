.setcpu "65816"
.segment "CODE"
.org $2E3F
map_control_0c2e3f:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count

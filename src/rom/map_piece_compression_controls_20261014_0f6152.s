.setcpu "65816"
.segment "CODE"
.org $6152
map_control_0f6152:
    .byte $E7 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count

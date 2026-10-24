.setcpu "65816"
.segment "CODE"
.org $7750
map_control_0f7750:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count

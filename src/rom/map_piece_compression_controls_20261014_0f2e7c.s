.setcpu "65816"
.segment "CODE"
.org $2E7C
map_control_0f2e7c:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $21 ; distance low bit/count
    .byte $E7 ; previous-row copy count

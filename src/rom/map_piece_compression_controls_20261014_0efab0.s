.setcpu "65816"
.segment "CODE"
.org $FAB0
map_control_0efab0:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $B0 ; row-distance/count

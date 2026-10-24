.setcpu "65816"
.segment "CODE"
.org $68F0
map_control_0d68f0:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E1 ; previous-row copy count

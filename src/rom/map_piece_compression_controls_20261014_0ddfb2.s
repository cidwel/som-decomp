.setcpu "65816"
.segment "CODE"
.org $DFB2
map_control_0ddfb2:
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count

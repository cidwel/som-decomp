.setcpu "65816"
.segment "CODE"
.org $BDFC
map_control_0fbdfc:
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count

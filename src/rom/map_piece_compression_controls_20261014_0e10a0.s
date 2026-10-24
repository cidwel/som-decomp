.setcpu "65816"
.segment "CODE"
.org $10A0
map_control_0e10a0:
    .byte $ED ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $31C0
map_control_0e31c0:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count

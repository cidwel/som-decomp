.setcpu "65816"
.segment "CODE"
.org $31C8
map_control_0f31c8:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count

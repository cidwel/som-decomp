.setcpu "65816"
.segment "CODE"
.org $6B27
map_control_0f6b27:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $44 ; row-distance/count

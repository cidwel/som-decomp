.setcpu "65816"
.segment "CODE"
.org $87B4
map_control_0f87b4:
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $21 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count

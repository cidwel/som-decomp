.setcpu "65816"
.segment "CODE"
.org $8A7A
map_control_0f8a7a:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count

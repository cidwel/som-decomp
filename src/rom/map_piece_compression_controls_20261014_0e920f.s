.setcpu "65816"
.segment "CODE"
.org $920F
map_control_0e920f:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count

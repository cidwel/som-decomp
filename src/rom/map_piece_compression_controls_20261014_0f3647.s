.setcpu "65816"
.segment "CODE"
.org $3647
map_control_0f3647:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $4D42
map_control_0d4d42:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $5A ; distance low bit/count

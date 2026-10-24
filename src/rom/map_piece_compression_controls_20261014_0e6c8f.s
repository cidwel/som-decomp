.setcpu "65816"
.segment "CODE"
.org $6C8F
map_control_0e6c8f:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count

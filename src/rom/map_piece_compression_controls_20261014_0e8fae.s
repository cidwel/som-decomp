.setcpu "65816"
.segment "CODE"
.org $8FAE
map_control_0e8fae:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count

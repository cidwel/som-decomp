.setcpu "65816"
.segment "CODE"
.org $4AF3
map_control_0d4af3:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count

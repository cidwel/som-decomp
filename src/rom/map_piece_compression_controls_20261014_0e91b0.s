.setcpu "65816"
.segment "CODE"
.org $91B0
map_control_0e91b0:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $24 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $543D
map_control_0d543d:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count

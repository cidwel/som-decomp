.setcpu "65816"
.segment "CODE"
.org $7406
map_control_0c7406:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count

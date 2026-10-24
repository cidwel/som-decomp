.setcpu "65816"
.segment "CODE"
.org $F1F0
map_control_0ff1f0:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count

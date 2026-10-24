.setcpu "65816"
.segment "CODE"
.org $928B
map_control_0c928b:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count

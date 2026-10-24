.setcpu "65816"
.segment "CODE"
.org $B30B
map_control_0fb30b:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count

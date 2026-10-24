.setcpu "65816"
.segment "CODE"
.org $8676
map_control_0c8676:
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count

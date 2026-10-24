.setcpu "65816"
.segment "CODE"
.org $DC79
map_control_0fdc79:
    .byte $EC ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C3 ; same-value copy count/distance

.setcpu "65816"
.segment "CODE"
.org $18EC
map_control_0c18ec:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count

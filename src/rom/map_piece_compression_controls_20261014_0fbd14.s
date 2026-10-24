.setcpu "65816"
.segment "CODE"
.org $BD14
map_control_0fbd14:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E7 ; previous-row copy count

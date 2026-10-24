.setcpu "65816"
.segment "CODE"
.org $AD79
map_control_0ead79:
    .byte $C4 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count

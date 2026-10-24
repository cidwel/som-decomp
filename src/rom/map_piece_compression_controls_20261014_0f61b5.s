.setcpu "65816"
.segment "CODE"
.org $61B5
map_control_0f61b5:
    .byte $F1 ; progressive-copy count
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
    .byte $C4 ; same-value copy count/distance

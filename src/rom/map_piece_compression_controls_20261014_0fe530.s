.setcpu "65816"
.segment "CODE"
.org $E530
map_control_0fe530:
    .byte $C1 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $41 ; distance low bit/count

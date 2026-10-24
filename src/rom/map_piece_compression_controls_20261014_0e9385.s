.setcpu "65816"
.segment "CODE"
.org $9385
map_control_0e9385:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count

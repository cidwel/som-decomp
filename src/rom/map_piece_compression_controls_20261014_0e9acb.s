.setcpu "65816"
.segment "CODE"
.org $9ACB
map_control_0e9acb:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $AA ; row-distance/count

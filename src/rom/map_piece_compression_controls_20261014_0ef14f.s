.setcpu "65816"
.segment "CODE"
.org $F14F
map_control_0ef14f:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count

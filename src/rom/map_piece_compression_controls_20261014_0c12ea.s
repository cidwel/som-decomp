.setcpu "65816"
.segment "CODE"
.org $12EA
map_control_0c12ea:
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $DF52
map_control_0fdf52:
    .byte $E5 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count

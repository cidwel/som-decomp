.setcpu "65816"
.segment "CODE"
.org $C55C
map_control_0ec55c:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E6 ; previous-row copy count

.setcpu "65816"
.segment "CODE"
.org $2CE1
map_control_0f2ce1:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E1 ; previous-row copy count

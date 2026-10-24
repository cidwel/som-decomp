.setcpu "65816"
.segment "CODE"
.org $7782
map_control_0c7782:
    .byte $E9 ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count

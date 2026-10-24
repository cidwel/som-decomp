.setcpu "65816"
.segment "CODE"
.org $804E
map_control_0d804e:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
    .byte $E3 ; previous-row copy count

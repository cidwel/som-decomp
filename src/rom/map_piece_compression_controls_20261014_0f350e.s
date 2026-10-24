.setcpu "65816"
.segment "CODE"
.org $350E
map_control_0f350e:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
    .byte $E4 ; previous-row copy count

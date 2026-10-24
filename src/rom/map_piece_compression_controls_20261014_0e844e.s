.setcpu "65816"
.segment "CODE"
.org $844E
map_control_0e844e:
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count

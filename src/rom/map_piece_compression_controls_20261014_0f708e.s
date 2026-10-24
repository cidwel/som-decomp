.setcpu "65816"
.segment "CODE"
.org $708E
map_control_0f708e:
    .byte $E9 ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E3 ; previous-row copy count

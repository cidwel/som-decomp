.setcpu "65816"
.segment "CODE"
.org $8D9E
map_control_0c8d9e:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count

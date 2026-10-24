.setcpu "65816"
.segment "CODE"
.org $E158
map_control_0ee158:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E2 ; previous-row copy count

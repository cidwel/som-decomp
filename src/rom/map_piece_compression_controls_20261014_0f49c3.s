.setcpu "65816"
.segment "CODE"
.org $49C3
map_control_0f49c3:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count

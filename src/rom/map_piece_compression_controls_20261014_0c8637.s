.setcpu "65816"
.segment "CODE"
.org $8637
map_control_0c8637:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E4 ; previous-row copy count

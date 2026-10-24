.setcpu "65816"
.segment "CODE"
.org $46F8
map_control_0d46f8:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E1 ; previous-row copy count

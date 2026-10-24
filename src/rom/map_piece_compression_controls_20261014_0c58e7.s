.setcpu "65816"
.segment "CODE"
.org $58E7
map_control_0c58e7:
    .byte $E3 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count

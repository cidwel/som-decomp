.setcpu "65816"
.segment "CODE"
.org $B2FE
map_control_0db2fe:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E3 ; previous-row copy count

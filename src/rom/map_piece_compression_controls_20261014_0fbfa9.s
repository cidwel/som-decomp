.setcpu "65816"
.segment "CODE"
.org $BFA9
map_control_0fbfa9:
    .byte $EA ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E7 ; previous-row copy count

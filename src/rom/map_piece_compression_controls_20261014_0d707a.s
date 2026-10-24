.setcpu "65816"
.segment "CODE"
.org $707A
map_control_0d707a:
    .byte $E6 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count

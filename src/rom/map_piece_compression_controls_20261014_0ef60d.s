.setcpu "65816"
.segment "CODE"
.org $F60D
map_control_0ef60d:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E3 ; previous-row copy count

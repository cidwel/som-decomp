.setcpu "65816"
.segment "CODE"
.org $105B
map_control_0e105b:
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count

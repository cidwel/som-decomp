.setcpu "65816"
.segment "CODE"
.org $6B23
map_control_0d6b23:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E4 ; previous-row copy count

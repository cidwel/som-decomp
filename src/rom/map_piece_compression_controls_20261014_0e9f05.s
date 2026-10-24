.setcpu "65816"
.segment "CODE"
.org $9F05
map_control_0e9f05:
    .byte $E7 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count

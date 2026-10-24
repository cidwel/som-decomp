.setcpu "65816"
.segment "CODE"
.org $352D
map_control_0e352d:
    .byte $E6 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $5D ; distance low bit/count

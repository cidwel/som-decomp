.setcpu "65816"
.segment "CODE"
.org $9D3A
map_control_0d9d3a:
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count

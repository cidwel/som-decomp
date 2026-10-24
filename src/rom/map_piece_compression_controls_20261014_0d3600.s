.setcpu "65816"
.segment "CODE"
.org $3600
map_control_0d3600:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E1 ; previous-row copy count

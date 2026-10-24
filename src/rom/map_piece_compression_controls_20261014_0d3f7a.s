.setcpu "65816"
.segment "CODE"
.org $3F7A
map_control_0d3f7a:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E4 ; previous-row copy count

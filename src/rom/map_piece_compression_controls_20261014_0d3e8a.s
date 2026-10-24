.setcpu "65816"
.segment "CODE"
.org $3E8A
map_control_0d3e8a:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E4 ; previous-row copy count

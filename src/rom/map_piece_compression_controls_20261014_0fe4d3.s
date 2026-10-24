.setcpu "65816"
.segment "CODE"
.org $E4D3
map_control_0fe4d3:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E1 ; previous-row copy count

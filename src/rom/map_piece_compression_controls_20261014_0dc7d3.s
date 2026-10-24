.setcpu "65816"
.segment "CODE"
.org $C7D3
map_control_0dc7d3:
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $15D3
map_control_0f15d3:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

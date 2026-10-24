.setcpu "65816"
.segment "CODE"
.org $70D3
map_control_0c70d3:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $4D3E
map_control_0c4d3e:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

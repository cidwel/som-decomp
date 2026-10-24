.setcpu "65816"
.segment "CODE"
.org $3D3F
map_control_0e3d3f:
    .byte $E4 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

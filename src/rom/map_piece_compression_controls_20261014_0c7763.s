.setcpu "65816"
.segment "CODE"
.org $7763
map_control_0c7763:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3D ; row-distance/count

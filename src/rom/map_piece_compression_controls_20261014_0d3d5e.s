.setcpu "65816"
.segment "CODE"
.org $3D5E
map_control_0d3d5e:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count

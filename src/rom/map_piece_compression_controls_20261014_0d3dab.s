.setcpu "65816"
.segment "CODE"
.org $3DAB
map_control_0d3dab:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count

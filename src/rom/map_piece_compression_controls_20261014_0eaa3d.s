.setcpu "65816"
.segment "CODE"
.org $AA3D
map_control_0eaa3d:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count

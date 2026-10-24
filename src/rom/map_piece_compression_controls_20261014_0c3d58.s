.setcpu "65816"
.segment "CODE"
.org $3D58
map_control_0c3d58:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count

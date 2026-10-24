.setcpu "65816"
.segment "CODE"
.org $6B3D
map_control_0f6b3d:
    .byte $EA ; backreference distance high bits
    .byte $A1 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count

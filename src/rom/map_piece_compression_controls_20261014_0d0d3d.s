.setcpu "65816"
.segment "CODE"
.org $0D3D
map_control_0d0d3d:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $CB ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $DF ; row-distance/count

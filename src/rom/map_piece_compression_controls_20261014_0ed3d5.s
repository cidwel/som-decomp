.setcpu "65816"
.segment "CODE"
.org $D3D5
map_control_0ed3d5:
    .byte $EB ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count

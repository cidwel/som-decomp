.setcpu "65816"
.segment "CODE"
.org $C3D4
map_control_0fc3d4:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count

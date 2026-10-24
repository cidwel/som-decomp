.setcpu "65816"
.segment "CODE"
.org $C4CE
map_control_0fc4ce:
    .byte $E0 ; previous-row copy escape
    .byte $45 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $63 ; row-distance/count

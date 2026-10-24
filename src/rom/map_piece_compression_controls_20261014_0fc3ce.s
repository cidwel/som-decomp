.setcpu "65816"
.segment "CODE"
.org $C3CE
map_control_0fc3ce:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count

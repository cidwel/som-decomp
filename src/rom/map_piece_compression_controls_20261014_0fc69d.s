.setcpu "65816"
.segment "CODE"
.org $C69D
map_control_0fc69d:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count

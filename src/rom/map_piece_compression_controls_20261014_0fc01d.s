.setcpu "65816"
.segment "CODE"
.org $C01D
map_control_0fc01d:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

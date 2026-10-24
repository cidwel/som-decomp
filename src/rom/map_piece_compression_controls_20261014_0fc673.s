.setcpu "65816"
.segment "CODE"
.org $C673
map_control_0fc673:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count

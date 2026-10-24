.setcpu "65816"
.segment "CODE"
.org $C249
map_control_0fc249:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count

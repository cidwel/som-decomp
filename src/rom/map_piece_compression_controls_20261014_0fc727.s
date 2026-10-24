.setcpu "65816"
.segment "CODE"
.org $C727
map_control_0fc727:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $43 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $87C4
map_control_0c87c4:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count

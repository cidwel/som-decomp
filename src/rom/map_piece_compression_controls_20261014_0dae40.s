.setcpu "65816"
.segment "CODE"
.org $AE40
map_control_0dae40:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count

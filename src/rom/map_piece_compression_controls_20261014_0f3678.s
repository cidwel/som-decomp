.setcpu "65816"
.segment "CODE"
.org $3678
map_control_0f3678:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count

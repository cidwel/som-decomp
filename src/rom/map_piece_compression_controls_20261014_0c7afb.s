.setcpu "65816"
.segment "CODE"
.org $7AFB
map_control_0c7afb:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count

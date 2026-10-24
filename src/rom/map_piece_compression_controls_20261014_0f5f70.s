.setcpu "65816"
.segment "CODE"
.org $5F70
map_control_0f5f70:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count

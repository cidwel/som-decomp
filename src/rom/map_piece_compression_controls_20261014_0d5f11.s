.setcpu "65816"
.segment "CODE"
.org $5F11
map_control_0d5f11:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count

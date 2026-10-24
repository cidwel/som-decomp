.setcpu "65816"
.segment "CODE"
.org $6294
map_control_0e6294:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $50 ; row-distance/count

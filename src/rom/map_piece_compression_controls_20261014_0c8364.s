.setcpu "65816"
.segment "CODE"
.org $8364
map_control_0c8364:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $37 ; distance low bit/count

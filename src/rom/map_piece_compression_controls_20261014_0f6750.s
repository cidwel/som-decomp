.setcpu "65816"
.segment "CODE"
.org $6750
map_control_0f6750:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $69 ; row-distance/count

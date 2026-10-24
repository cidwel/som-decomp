.setcpu "65816"
.segment "CODE"
.org $6758
map_control_0f6758:
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count

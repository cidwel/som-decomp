.setcpu "65816"
.segment "CODE"
.org $6776
map_control_0f6776:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count

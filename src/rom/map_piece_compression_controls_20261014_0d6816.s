.setcpu "65816"
.segment "CODE"
.org $6816
map_control_0d6816:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count

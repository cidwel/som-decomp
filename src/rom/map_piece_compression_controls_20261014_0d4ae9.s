.setcpu "65816"
.segment "CODE"
.org $4AE9
map_control_0d4ae9:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count

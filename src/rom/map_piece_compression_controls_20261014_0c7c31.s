.setcpu "65816"
.segment "CODE"
.org $7C31
map_control_0c7c31:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $56 ; row-distance/count

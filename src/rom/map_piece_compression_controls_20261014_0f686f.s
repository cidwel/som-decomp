.setcpu "65816"
.segment "CODE"
.org $686F
map_control_0f686f:
    .byte $EA ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count

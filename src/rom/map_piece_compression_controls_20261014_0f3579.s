.setcpu "65816"
.segment "CODE"
.org $3579
map_control_0f3579:
    .byte $EA ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $2A7C
map_control_0f2a7c:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count

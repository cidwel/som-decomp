.setcpu "65816"
.segment "CODE"
.org $200C
map_control_0c200c:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count

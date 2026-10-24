.setcpu "65816"
.segment "CODE"
.org $B37C
map_control_0db37c:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count

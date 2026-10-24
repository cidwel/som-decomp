.setcpu "65816"
.segment "CODE"
.org $B6CE
map_control_0fb6ce:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $B3 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $E6F3
map_control_0fe6f3:
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count

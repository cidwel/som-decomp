.setcpu "65816"
.segment "CODE"
.org $E0C9
map_control_0fe0c9:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count

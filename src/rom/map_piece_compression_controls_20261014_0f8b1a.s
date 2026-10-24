.setcpu "65816"
.segment "CODE"
.org $8B1A
map_control_0f8b1a:
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $2B77
map_control_0f2b77:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count

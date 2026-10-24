.setcpu "65816"
.segment "CODE"
.org $7676
map_control_0e7676:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count

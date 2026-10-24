.setcpu "65816"
.segment "CODE"
.org $B877
map_control_0db877:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $B1EA
map_control_0fb1ea:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $0FB3
map_control_0c0fb3:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count

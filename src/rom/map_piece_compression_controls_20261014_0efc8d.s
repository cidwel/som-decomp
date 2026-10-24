.setcpu "65816"
.segment "CODE"
.org $FC8D
map_control_0efc8d:
    .byte $E0 ; previous-row copy escape
    .byte $B8 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count

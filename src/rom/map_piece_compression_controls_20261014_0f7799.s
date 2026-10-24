.setcpu "65816"
.segment "CODE"
.org $7799
map_control_0f7799:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $51 ; row-distance/count

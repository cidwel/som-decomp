.setcpu "65816"
.segment "CODE"
.org $98A0
map_control_0d98a0:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count

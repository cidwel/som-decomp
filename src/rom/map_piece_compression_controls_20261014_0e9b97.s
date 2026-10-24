.setcpu "65816"
.segment "CODE"
.org $9B97
map_control_0e9b97:
    .byte $C4 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $A8 ; row-distance/count

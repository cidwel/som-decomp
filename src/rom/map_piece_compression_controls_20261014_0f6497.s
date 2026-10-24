.setcpu "65816"
.segment "CODE"
.org $6497
map_control_0f6497:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $C1 ; same-value copy count/distance

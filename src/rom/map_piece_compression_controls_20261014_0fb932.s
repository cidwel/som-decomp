.setcpu "65816"
.segment "CODE"
.org $B932
map_control_0fb932:
    .byte $C7 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $CB ; row-distance/count
    .byte $C3 ; same-value copy count/distance

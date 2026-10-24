.setcpu "65816"
.segment "CODE"
.org $A3F3
map_control_0ea3f3:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count

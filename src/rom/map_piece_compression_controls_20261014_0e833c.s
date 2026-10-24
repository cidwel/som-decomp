.setcpu "65816"
.segment "CODE"
.org $833C
map_control_0e833c:
    .byte $C2 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $D6DD
map_control_0fd6dd:
    .byte $C5 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count

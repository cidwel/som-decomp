.setcpu "65816"
.segment "CODE"
.org $D98F
map_control_0ed98f:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C9 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count

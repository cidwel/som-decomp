.setcpu "65816"
.segment "CODE"
.org $5D93
map_control_0f5d93:
    .byte $DE ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count

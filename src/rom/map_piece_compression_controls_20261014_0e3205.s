.setcpu "65816"
.segment "CODE"
.org $3205
map_control_0e3205:
    .byte $ED ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E6 ; previous-row copy count

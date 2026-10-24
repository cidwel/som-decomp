.setcpu "65816"
.segment "CODE"
.org $7DA9
map_control_0f7da9:
    .byte $E6 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance

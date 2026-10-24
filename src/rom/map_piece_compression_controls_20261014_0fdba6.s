.setcpu "65816"
.segment "CODE"
.org $DBA6
map_control_0fdba6:
    .byte $C7 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance

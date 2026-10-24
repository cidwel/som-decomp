.setcpu "65816"
.segment "CODE"
.org $8025
map_control_0d8025:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count

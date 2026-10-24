.setcpu "65816"
.segment "CODE"
.org $E0F7
map_control_0de0f7:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count

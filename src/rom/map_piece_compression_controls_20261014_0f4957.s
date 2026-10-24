.setcpu "65816"
.segment "CODE"
.org $4957
map_control_0f4957:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance

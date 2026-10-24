.setcpu "65816"
.segment "CODE"
.org $17DC
map_control_0f17dc:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E6 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance

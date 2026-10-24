.setcpu "65816"
.segment "CODE"
.org $4936
map_control_0f4936:
    .byte $E7 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance

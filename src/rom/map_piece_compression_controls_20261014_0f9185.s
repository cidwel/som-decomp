.setcpu "65816"
.segment "CODE"
.org $9185
map_control_0f9185:
    .byte $E2 ; previous-row copy count
    .byte $DE ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count

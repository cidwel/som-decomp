.setcpu "65816"
.segment "CODE"
.org $58BE
map_control_0f58be:
    .byte $D2 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E2 ; previous-row copy count

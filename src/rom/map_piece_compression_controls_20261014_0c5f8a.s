.setcpu "65816"
.segment "CODE"
.org $5F8A
map_control_0c5f8a:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E4 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance

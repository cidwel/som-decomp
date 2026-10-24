.setcpu "65816"
.segment "CODE"
.org $51C9
map_control_0f51c9:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count

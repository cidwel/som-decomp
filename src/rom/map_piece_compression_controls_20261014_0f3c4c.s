.setcpu "65816"
.segment "CODE"
.org $3C4C
map_control_0f3c4c:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count

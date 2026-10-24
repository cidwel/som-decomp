.setcpu "65816"
.segment "CODE"
.org $11DA
map_control_0f11da:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count

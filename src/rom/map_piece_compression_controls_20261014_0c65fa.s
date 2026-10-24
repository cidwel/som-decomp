.setcpu "65816"
.segment "CODE"
.org $65FA
map_control_0c65fa:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance

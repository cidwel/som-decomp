.setcpu "65816"
.segment "CODE"
.org $FCC0
map_control_0ffcc0:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance

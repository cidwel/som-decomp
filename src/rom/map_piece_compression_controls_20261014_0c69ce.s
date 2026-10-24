.setcpu "65816"
.segment "CODE"
.org $69CE
map_control_0c69ce:
    .byte $DF ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count

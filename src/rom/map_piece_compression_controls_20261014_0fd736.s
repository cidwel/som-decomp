.setcpu "65816"
.segment "CODE"
.org $D736
map_control_0fd736:
    .byte $C6 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count

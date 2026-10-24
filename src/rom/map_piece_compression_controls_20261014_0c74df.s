.setcpu "65816"
.segment "CODE"
.org $74DF
map_control_0c74df:
    .byte $EE ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $C7 ; same-value copy count/distance

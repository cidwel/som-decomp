.setcpu "65816"
.segment "CODE"
.org $C92C
map_control_0ec92c:
    .byte $F1 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $C1 ; same-value copy count/distance

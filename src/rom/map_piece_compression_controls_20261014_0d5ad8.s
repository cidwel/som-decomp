.setcpu "65816"
.segment "CODE"
.org $5AD8
map_control_0d5ad8:
    .byte $C5 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count

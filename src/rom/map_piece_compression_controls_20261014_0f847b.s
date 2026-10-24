.setcpu "65816"
.segment "CODE"
.org $847B
map_control_0f847b:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance

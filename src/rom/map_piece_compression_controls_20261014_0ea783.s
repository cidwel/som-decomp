.setcpu "65816"
.segment "CODE"
.org $A783
map_control_0ea783:
    .byte $C1 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count

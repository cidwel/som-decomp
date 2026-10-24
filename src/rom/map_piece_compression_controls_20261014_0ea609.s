.setcpu "65816"
.segment "CODE"
.org $A609
map_control_0ea609:
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count

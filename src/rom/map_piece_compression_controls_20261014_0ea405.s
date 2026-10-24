.setcpu "65816"
.segment "CODE"
.org $A405
map_control_0ea405:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance

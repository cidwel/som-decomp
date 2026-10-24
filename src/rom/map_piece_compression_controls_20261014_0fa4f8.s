.setcpu "65816"
.segment "CODE"
.org $A4F8
map_control_0fa4f8:
    .byte $CD ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $EDBE
map_control_0fedbe:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $91 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $90 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance

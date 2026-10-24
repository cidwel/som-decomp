.setcpu "65816"
.segment "CODE"
.org $F30E
map_control_0cf30e:
    .byte $CD ; same-value copy count/distance
    .byte $F4 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count

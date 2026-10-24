.setcpu "65816"
.segment "CODE"
.org $871A
map_control_0c871a:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $C6 ; same-value copy count/distance

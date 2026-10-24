.setcpu "65816"
.segment "CODE"
.org $BB8A
map_control_0ebb8a:
    .byte $EE ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count

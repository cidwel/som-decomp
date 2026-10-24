.setcpu "65816"
.segment "CODE"
.org $5079
map_control_0c5079:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $F1 ; progressive-copy count
    .byte $C7 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $87 ; distance low bit/count

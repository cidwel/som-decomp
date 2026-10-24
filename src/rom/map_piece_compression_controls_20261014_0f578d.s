.setcpu "65816"
.segment "CODE"
.org $578D
map_control_0f578d:
    .byte $D7 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count

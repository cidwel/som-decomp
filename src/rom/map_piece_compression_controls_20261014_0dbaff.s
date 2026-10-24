.setcpu "65816"
.segment "CODE"
.org $BAFF
map_control_0dbaff:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance

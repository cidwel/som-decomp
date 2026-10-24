.setcpu "65816"
.segment "CODE"
.org $BAEF
map_control_0dbaef:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance

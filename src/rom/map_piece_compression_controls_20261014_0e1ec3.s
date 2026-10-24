.setcpu "65816"
.segment "CODE"
.org $1EC3
map_control_0e1ec3:
    .byte $C1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count

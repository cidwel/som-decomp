.setcpu "65816"
.segment "CODE"
.org $3D17
map_control_0e3d17:
    .byte $F2 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance

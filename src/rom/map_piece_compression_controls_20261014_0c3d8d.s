.setcpu "65816"
.segment "CODE"
.org $3D8D
map_control_0c3d8d:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $F1 ; progressive-copy count
    .byte $D1 ; same-value copy count/distance

.setcpu "65816"
.segment "CODE"
.org $3D9C
map_control_0c3d9c:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count

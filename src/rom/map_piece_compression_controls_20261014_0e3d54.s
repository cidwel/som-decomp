.setcpu "65816"
.segment "CODE"
.org $3D54
map_control_0e3d54:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C1 ; same-value copy count/distance

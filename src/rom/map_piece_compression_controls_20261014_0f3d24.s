.setcpu "65816"
.segment "CODE"
.org $3D24
map_control_0f3d24:
    .byte $CA ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count

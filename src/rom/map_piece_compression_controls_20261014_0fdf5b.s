.setcpu "65816"
.segment "CODE"
.org $DF5B
map_control_0fdf5b:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $D9 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count

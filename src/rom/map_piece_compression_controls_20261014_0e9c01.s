.setcpu "65816"
.segment "CODE"
.org $9C01
map_control_0e9c01:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $37 ; row-distance/count

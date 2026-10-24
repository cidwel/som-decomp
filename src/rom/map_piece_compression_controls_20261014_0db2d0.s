.setcpu "65816"
.segment "CODE"
.org $B2D0
map_control_0db2d0:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E4 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $C5 ; same-value copy count/distance

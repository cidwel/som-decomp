.setcpu "65816"
.segment "CODE"
.org $4A30
map_control_0e4a30:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance

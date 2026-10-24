.setcpu "65816"
.segment "CODE"
.org $58EE
map_control_0d58ee:
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
    .byte $C1 ; same-value copy count/distance

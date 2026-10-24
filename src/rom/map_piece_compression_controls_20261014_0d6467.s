.setcpu "65816"
.segment "CODE"
.org $6467
map_control_0d6467:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $C3 ; row-distance/count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count

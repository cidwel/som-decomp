.setcpu "65816"
.segment "CODE"
.org $18E2
map_control_0e18e2:
    .byte $D5 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count

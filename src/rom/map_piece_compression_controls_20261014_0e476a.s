.setcpu "65816"
.segment "CODE"
.org $476A
map_control_0e476a:
    .byte $EB ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance

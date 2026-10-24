.setcpu "65816"
.segment "CODE"
.org $DCCC
map_control_0edccc:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $C5 ; same-value copy count/distance

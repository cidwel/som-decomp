.setcpu "65816"
.segment "CODE"
.org $4F44
map_control_0e4f44:
    .byte $E5 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance

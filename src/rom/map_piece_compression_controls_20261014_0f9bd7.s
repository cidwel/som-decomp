.setcpu "65816"
.segment "CODE"
.org $9BD7
map_control_0f9bd7:
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $458B
map_control_0e458b:
    .byte $E5 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count

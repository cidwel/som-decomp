.setcpu "65816"
.segment "CODE"
.org $BCCC
map_control_0fbccc:
    .byte $C1 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E7 ; previous-row copy count

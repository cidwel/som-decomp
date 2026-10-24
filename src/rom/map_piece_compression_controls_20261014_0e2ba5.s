.setcpu "65816"
.segment "CODE"
.org $2BA5
map_control_0e2ba5:
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E7 ; previous-row copy count

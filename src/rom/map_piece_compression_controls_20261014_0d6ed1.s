.setcpu "65816"
.segment "CODE"
.org $6ED1
map_control_0d6ed1:
    .byte $DF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E3 ; previous-row copy count

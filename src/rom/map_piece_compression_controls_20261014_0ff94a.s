.setcpu "65816"
.segment "CODE"
.org $F94A
map_control_0ff94a:
    .byte $C1 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count

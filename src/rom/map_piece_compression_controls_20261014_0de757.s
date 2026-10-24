.setcpu "65816"
.segment "CODE"
.org $E757
map_control_0de757:
    .byte $DA ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count

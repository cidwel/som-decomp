.setcpu "65816"
.segment "CODE"
.org $A3CD
map_control_0fa3cd:
    .byte $C9 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count

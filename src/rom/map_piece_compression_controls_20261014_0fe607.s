.setcpu "65816"
.segment "CODE"
.org $E607
map_control_0fe607:
    .byte $CB ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count

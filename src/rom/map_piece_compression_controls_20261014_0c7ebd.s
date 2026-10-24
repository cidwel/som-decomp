.setcpu "65816"
.segment "CODE"
.org $7EBD
map_control_0c7ebd:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $D7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count

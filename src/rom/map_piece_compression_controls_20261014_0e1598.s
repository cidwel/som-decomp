.setcpu "65816"
.segment "CODE"
.org $1598
map_control_0e1598:
    .byte $DB ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count

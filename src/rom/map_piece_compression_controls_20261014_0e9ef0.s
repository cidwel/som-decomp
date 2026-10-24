.setcpu "65816"
.segment "CODE"
.org $9EF0
map_control_0e9ef0:
    .byte $DB ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count

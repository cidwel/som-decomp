.setcpu "65816"
.segment "CODE"
.org $183C
map_control_0e183c:
    .byte $DB ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count

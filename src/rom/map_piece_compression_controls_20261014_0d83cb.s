.setcpu "65816"
.segment "CODE"
.org $83CB
map_control_0d83cb:
    .byte $C1 ; same-value copy count/distance
    .byte $DB ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count

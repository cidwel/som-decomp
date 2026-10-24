.setcpu "65816"
.segment "CODE"
.org $3DC8
map_control_0e3dc8:
    .byte $DB ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C1 ; same-value copy count/distance

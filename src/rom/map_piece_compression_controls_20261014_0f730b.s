.setcpu "65816"
.segment "CODE"
.org $730B
map_control_0f730b:
    .byte $C1 ; same-value copy count/distance
    .byte $DB ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C9 ; same-value copy count/distance

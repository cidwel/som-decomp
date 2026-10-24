.setcpu "65816"
.segment "CODE"
.org $A534
map_control_0fa534:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E3 ; previous-row copy count

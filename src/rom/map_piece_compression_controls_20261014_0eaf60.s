.setcpu "65816"
.segment "CODE"
.org $AF60
map_control_0eaf60:
    .byte $C7 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C1 ; same-value copy count/distance

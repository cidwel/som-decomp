.setcpu "65816"
.segment "CODE"
.org $5E58
map_control_0d5e58:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $A6 ; row-distance/count
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count

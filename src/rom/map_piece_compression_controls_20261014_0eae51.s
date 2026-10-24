.setcpu "65816"
.segment "CODE"
.org $AE51
map_control_0eae51:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $D5 ; same-value copy count/distance

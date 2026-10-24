.setcpu "65816"
.segment "CODE"
.org $9F4B
map_control_0e9f4b:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $E1 ; previous-row copy count

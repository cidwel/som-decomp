.setcpu "65816"
.segment "CODE"
.org $1FA0
map_control_0e1fa0:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance

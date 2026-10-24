.setcpu "65816"
.segment "CODE"
.org $57E2
map_control_0c57e2:
    .byte $C3 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E3 ; previous-row copy count

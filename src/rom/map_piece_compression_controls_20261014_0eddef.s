.setcpu "65816"
.segment "CODE"
.org $DDEF
map_control_0eddef:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count

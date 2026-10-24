.setcpu "65816"
.segment "CODE"
.org $21AB
map_control_0e21ab:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count

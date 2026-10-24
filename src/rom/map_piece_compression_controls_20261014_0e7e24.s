.setcpu "65816"
.segment "CODE"
.org $7E24
map_control_0e7e24:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count

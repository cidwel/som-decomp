.setcpu "65816"
.segment "CODE"
.org $AA7C
map_control_0eaa7c:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count

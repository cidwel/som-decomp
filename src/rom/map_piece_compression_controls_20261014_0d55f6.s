.setcpu "65816"
.segment "CODE"
.org $55F6
map_control_0d55f6:
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance

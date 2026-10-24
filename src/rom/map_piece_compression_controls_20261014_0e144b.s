.setcpu "65816"
.segment "CODE"
.org $144B
map_control_0e144b:
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $09 ; distance low bit/count

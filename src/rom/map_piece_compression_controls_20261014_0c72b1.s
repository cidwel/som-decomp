.setcpu "65816"
.segment "CODE"
.org $72B1
map_control_0c72b1:
    .byte $C4 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count

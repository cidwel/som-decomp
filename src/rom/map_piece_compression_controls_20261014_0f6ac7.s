.setcpu "65816"
.segment "CODE"
.org $6AC7
map_control_0f6ac7:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E5 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C9 ; same-value copy count/distance

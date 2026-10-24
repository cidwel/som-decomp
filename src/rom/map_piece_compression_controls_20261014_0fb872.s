.setcpu "65816"
.segment "CODE"
.org $B872
map_control_0fb872:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $56 ; row-distance/count
    .byte $C4 ; same-value copy count/distance

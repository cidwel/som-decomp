.setcpu "65816"
.segment "CODE"
.org $79CD
map_control_0f79cd:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count

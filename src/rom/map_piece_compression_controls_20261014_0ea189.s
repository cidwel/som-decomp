.setcpu "65816"
.segment "CODE"
.org $A189
map_control_0ea189:
    .byte $E1 ; previous-row copy count
    .byte $D5 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count

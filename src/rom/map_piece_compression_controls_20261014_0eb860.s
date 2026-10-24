.setcpu "65816"
.segment "CODE"
.org $B860
map_control_0eb860:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count

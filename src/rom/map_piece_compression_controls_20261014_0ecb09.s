.setcpu "65816"
.segment "CODE"
.org $CB09
map_control_0ecb09:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance

.setcpu "65816"
.segment "CODE"
.org $3C97
map_control_0f3c97:
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count

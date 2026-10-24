.setcpu "65816"
.segment "CODE"
.org $4BBD
map_control_0d4bbd:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $C1 ; same-value copy count/distance

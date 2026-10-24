.setcpu "65816"
.segment "CODE"
.org $C30E
map_control_0dc30e:
    .byte $DF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $2A ; distance low bit/count

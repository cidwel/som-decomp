.setcpu "65816"
.segment "CODE"
.org $AE71
map_control_0fae71:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
    .byte $CA ; same-value copy count/distance

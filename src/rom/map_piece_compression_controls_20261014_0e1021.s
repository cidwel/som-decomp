.setcpu "65816"
.segment "CODE"
.org $1021
map_control_0e1021:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
